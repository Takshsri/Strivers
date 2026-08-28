// #include <iostream>
// #include <vector>
// using namespace std;

// int Rec(vector<int>& price, int idx, int length) {

//     // Only piece of length 1 is available
//     if(idx == 0) {
//         return length * price[0];
//     }

//     int notTake = Rec(price, idx - 1, length);

//     int take = 0;

//     int rodLength = idx + 1;

//     if(rodLength <= length) {
//         take = price[idx] +
//                Rec(price, idx, length - rodLength);
//     }

//     return max(take, notTake);
// }


// int RecM(vector<int>& price,
//          int idx,
//          int length,
//          vector<vector<int>>& dp) {

//     if(idx == 0) {
//         return length * price[0];
//     }

//     if(dp[idx][length] != -1)
//         return dp[idx][length];

//     int notTake =
//         RecM(price, idx - 1, length, dp);

//     int take = 0;

//     int rodLength = idx + 1;

//     if(rodLength <= length) {
//         take = price[idx] +
//                RecM(price,
//                     idx,
//                     length - rodLength,
//                     dp);
//     }

//     return dp[idx][length] =
//            max(take, notTake);
// }



// int Tabulation(vector<int>& price, int n) {

//     vector<vector<int>> dp(n,vector<int>(n + 1, 0));

//     // Only piece of length 1
//     for(int length = 0; length <= n; length++) {
//         dp[0][length] =
//             length * price[0];
//     }

//     for(int i = 1; i < n; i++) {

//         int rodLength = i + 1;

//         for(int length = 0; length <= n; length++) {

//             int notTake = dp[i - 1][length];

//             int take = 0;

//             if(rodLength <= length) {

//                 take = price[i] +
//                        dp[i][length - rodLength];
//             }

//             dp[i][length] =
//                 max(take, notTake);
//         }
//     }

//     return dp[n - 1][n];
// }


// int main() {

//     vector<int> price = {1,5,8,9,10,17,17,20};

//     int n = price.size();

//     cout << Rec(price, n - 1, n)<<endl;;
//     vector<vector<int>> dp(n,vector<int>(n + 1, -1));

//     cout << RecM(price, n - 1, n, dp)<<endl;
//     cout << Tabulation(price, n);

//     return 0;
// }
// If they are given given lenth of size

#include <iostream>
#include <vector>
using namespace std;


// 1. RECURSION
int Rec(vector<int>& price, int idx, int rodLength) {

    // Only piece of length 1
    if(idx == 0) {
        return rodLength * price[0];
    }

    int notTake = Rec(price, idx - 1, rodLength);

    int take = 0;
    int pieceLength = idx + 1;

    if(pieceLength <= rodLength) {
        // Same idx because we can use this length again
        take = price[idx] +
               Rec(price, idx, rodLength - pieceLength);
    }

    return max(take, notTake);
}


// 2. MEMOIZATION
int RecM(vector<int>& price,
         int idx,
         int rodLength,
         vector<vector<int>>& dp) {

    if(idx == 0) {
        return rodLength * price[0];
    }

    if(dp[idx][rodLength] != -1)
        return dp[idx][rodLength];

    int notTake =
        RecM(price, idx - 1, rodLength, dp);

    int take = 0;
    int pieceLength = idx + 1;

    if(pieceLength <= rodLength) {
        take = price[idx] +
               RecM(price,
                    idx,
                    rodLength - pieceLength,
                    dp);
    }

    return dp[idx][rodLength] =
           max(take, notTake);
}


// 3. TABULATION
int Tabulation(vector<int>& price, int rodLength) {

    int n = price.size();

    vector<vector<int>> dp(
        n,
        vector<int>(rodLength + 1, 0)
    );

    // Base case:
    // Only pieces of length 1 are available
    for(int length = 0; length <= rodLength; length++) {
        dp[0][length] =
            length * price[0];
    }
 
    for(int i = 1; i < n; i++) {

        int pieceLength = i + 1;

        for(int length = 0;
            length <= rodLength;
            length++) {

            int notTake = dp[i - 1][length];

            int take = 0;

            if(pieceLength <= length) {
                take = price[i] +
                       dp[i][length - pieceLength];
            }

            dp[i][length] =
                max(take, notTake);
        }
    }

    return dp[n - 1][rodLength];
}


int main() {

    vector<int> price = {
        1, 5, 8, 9, 10, 17,
        17, 20, 24, 30, 35, 40
    };

    int rodLength = 12;

    // Recursion
    cout << "Recursion: "
         << Rec(price, price.size() - 1, rodLength)
         << endl;


    // Memoization
    vector<vector<int>> dp(
        price.size(),
        vector<int>(rodLength + 1, -1)
    );

    cout << "Memoization: "
         << RecM(price,
                 price.size() - 1,
                 rodLength,
                 dp)
         << endl;


    // Tabulation
    cout << "Tabulation: "
         << Tabulation(price, rodLength)
         << endl;

    return 0;
}