#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(vector<int>& a, int m, int k, int day) {
    int bouquets = 0;
    int flowers = 0;

    for (int i = 0; i < a.size(); i++) {

        if (a[i] <= day) {
            flowers++;

            if (flowers == k) {
                bouquets++;
                flowers = 0; 
            }
        }
        else {
            flowers = 0;      
        }
    }

    return bouquets >= m;
}

int Bouquet(vector<int>& a, int m, int k) {

    int n = a.size();

    // Not enough flowers
    if (1LL * m * k > n)
        return -1;

    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());

    int ans = -1;
 
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (possible(a, m, k, mid)) {
            ans = mid;
            high = mid - 1;    // try fewer days
        }
        else {
            low = mid + 1;     // need more days
        }
    }

    return ans;
}

int main() {

    vector<int> a = {3,4,2,6,13,8,5};

    int m = 3;
    int k = 2;

    cout << Bouquet(a, m, k);

    return 0;
}