#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Distance(vector<int>& a, vector<int>& b) {
    int n = a.size();

    // Store:
    // {difference, index}
    // difference = B_cost - A_cost
    vector<pair<int, int>> employees;

    for (int i = 0; i < n; i++) {
        int bCost = min(a[i], b[i]) + b[i];

        int difference = bCost - a[i];

        employees.push_back({difference, i});
    }

    // Largest difference means more beneficial to send to A
    sort(employees.begin(), employees.end(),
         greater<pair<int, int>>());

    int sum = 0;

    // First n/2 employees -> A
    for (int i = 0; i < n / 2; i++) {
        int index = employees[i].second;
        sum += a[index];
    }

    // Remaining employees -> B
    for (int i = n / 2; i < n; i++) {
        int index = employees[i].second;

        int bCost = min(a[index], b[index]) + b[index];

        sum += bCost;
    }

    return sum;
}

int main() {
    vector<int> a = {10, 30, 50, 20};
    vector<int> b = {20, 10, 40, 30};

    cout << Distance(a, b) << endl;

    return 0;
}