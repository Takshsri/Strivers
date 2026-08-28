#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& a) {

    int n = a.size();

    sort(a.begin(), a.end());

    // dp[i] = length of largest divisible subset
    // ending at index i
    vector<int> dp(n, 1);

    // parent[i] = previous index used to construct subset
    vector<int> parent(n, -1);

    int maxi = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (a[i] % a[j] == 0 &&
                dp[i] < dp[j] + 1) {

                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        // Keep track of longest subset
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> ans;

    while (lastIndex != -1) {
        ans.push_back(a[lastIndex]);
        lastIndex = parent[lastIndex];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<int> a = {1, 2, 4, 8};

    vector<int> ans = largestDivisibleSubset(a);

    cout << "Largest Divisible Subset: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}