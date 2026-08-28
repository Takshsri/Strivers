#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// 1. RECURSION
int MinTriangle(int i, int j, vector<vector<int>>& triangle) {

    // Last row
    if (i == triangle.size() - 1)
        return triangle[i][j];

    int down = MinTriangle(i + 1, j, triangle);
    int diagonal = MinTriangle(i + 1, j + 1, triangle);

    return triangle[i][j] + min(down, diagonal);
}


// 2. MEMOIZATION
int MinTriangleM(int i, int j,
                 vector<vector<int>>& triangle,
                 vector<vector<int>>& dp) {

    // Last row
    if (i == triangle.size() - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = MinTriangleM(i + 1, j, triangle, dp);
    int diagonal = MinTriangleM(i + 1, j + 1, triangle, dp);

    return dp[i][j] =
        triangle[i][j] + min(down, diagonal);
}


// 3. TABULATION
int Tabulation(vector<vector<int>>& triangle) {

    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Copy last row
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Bottom-up
    for (int i = n - 2; i >= 0; i--) {

        for (int j = 0; j <= i; j++) {

            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];

            dp[i][j] =
                triangle[i][j] + min(down, diagonal);
        }
    }

    return dp[0][0];
}


int main() {

    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Recursion: "
         << MinTriangle(0, 0, triangle) << endl;

    cout << "Memoization: "
         << MinTriangleM(0, 0, triangle, dp) << endl;

    cout << "Tabulation: " 
         << Tabulation(triangle) << endl;

    return 0;
}