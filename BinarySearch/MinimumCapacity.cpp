#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool possible(vector<int>& weights, int days, int capacity) {

    int current = 0;
    int usedDays = 1;

    for(int w : weights) {

        if(current + w <= capacity) {
            current += w;
        }
        else {
            usedDays++;
            current = w;
        }
    }

    return usedDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {

    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(possible(weights, days, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDays(weights, days);

    return 0;
}