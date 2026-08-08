#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Merge(vector<vector<int>>& a, vector<int>& newInterval) {

    int n = a.size();
    int idx = 0;

    vector<vector<int>> res;

    // Left part
    while (idx < n && a[idx][1] < newInterval[0]) {
        res.push_back(a[idx]);
        idx++;
    }

    // Overlapping part
    while (idx < n && a[idx][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], a[idx][0]);
        newInterval[1] = max(newInterval[1], a[idx][1]);
        idx++;
    }

    res.push_back(newInterval);

    // Right part
    while (idx < n) {
        res.push_back(a[idx]);
        idx++;
    }

    return res;
}

int main() {

    vector<vector<int>> a = {{1,2},{3,4},{7,8}};

    vector<int> newInterval = {4,5};

    vector<vector<int>> res = Merge(a, newInterval);

    for (auto interval : res) {
        cout << "[";
        for (int j = 0; j < interval.size(); j++) {
            cout << interval[j];
            if (j + 1 < interval.size())
                cout << ",";
        }
        cout << "] ";
    }
}