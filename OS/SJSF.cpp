#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SJFS(vector<int>& at, vector<int>& bt) {
    int n = at.size();

    vector<int> ct(n);
    vector<int> tat(n);
    vector<int> wt(n);
    vector<bool> completed(n, false);

    int time = 0;
    int completedCount = 0;

    while (completedCount < n) {

        int shortest = -1;

        // Find the shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time) {

                if (shortest == -1 ||
                    bt[i] < bt[shortest] ||
                    (bt[i] == bt[shortest] && at[i] < at[shortest])) {
                    
                    shortest = i;
                }
            }
        }

        // If no process has arrived yet
        if (shortest == -1) {
            time++;
            continue;
        }

        // Execute the selected process
        time += bt[shortest];

        ct[shortest] = time;

        tat[shortest] = ct[shortest] - at[shortest];

        wt[shortest] = tat[shortest] - bt[shortest];

        completed[shortest] = true;
        completedCount++;
    }

    cout << "CT: ";
    for (int i = 0; i < n; i++) {
        cout << ct[i] << " ";
    }

    cout << endl;

    cout << "TAT: ";
    for (int i = 0; i < n; i++) {
        cout << tat[i] << " ";
    }

    cout << endl;

    cout << "WT: ";
    for (int i = 0; i < n; i++) {
        cout << wt[i] << " ";
    }

    cout << endl;
}

int main() {

    vector<int> at = {1, 2, 0, 4};
    vector<int> bt = {3, 4, 2, 4};

    SJFS(at, bt);

    return 0;
}