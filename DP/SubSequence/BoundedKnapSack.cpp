#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive
int Rec(vector<int>& wt, vector<int>& val, int idx, int capacity) {

    if(idx == 0) {
        return (capacity / wt[0]) * val[0];  //taking the same item multiple times, so we can take it as many times as it fits in the capacity
    }

    int notTake = Rec(wt, val, idx - 1, capacity);

    int take = 0;

    if(wt[idx] <= capacity) { 
        // idx stays same because we can take the item again
        take = val[idx] + Rec(wt, val, idx, capacity - wt[idx]);
    }

    return max(take, notTake);
}


// Memoization
int RecM(vector<int>& wt, vector<int>& val,
         int idx, int capacity,
         vector<vector<int>>& dp) {

    if(idx == 0) {
        return (capacity / wt[0]) * val[0];
    }

    if(dp[idx][capacity] != -1)
        return dp[idx][capacity];

    int notTake = RecM(wt, val, idx - 1, capacity, dp);

    int take = INT_MIN;

    if(wt[idx] <= capacity) {
        take = val[idx] +
               RecM(wt, val, idx, capacity - wt[idx], dp);
    }

    return dp[idx][capacity] = max(take, notTake);
}


// Tabulation
int Tabulation(vector<int>& wt, vector<int>& val, int capacity) {

    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Base case
    for(int w = 0; w <= capacity; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for(int i = 1; i < n; i++) {

        for(int w = 0; w <= capacity; w++) {

            int notTake = dp[i - 1][w];

            int take = 0;

            if(wt[i] <= w) {
                // Same row because item can be reused
                take = val[i] + dp[i][w - wt[i]];
            }

            dp[i][w] = max(take, notTake);
        }
    } 

    return dp[n - 1][capacity]; 
}


int main() {

    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};

    int capacity = 10;

    vector<vector<int>> dp(
        wt.size(),
        vector<int>(capacity + 1, -1)
    );

    cout << Rec(wt, val, wt.size() - 1, capacity) << endl;

    cout << RecM(wt, val, wt.size() - 1, capacity, dp) << endl;

    cout << Tabulation(wt, val, capacity) << endl;
}