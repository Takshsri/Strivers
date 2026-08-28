#include<iostream>
#include<vector>
using namespace std;

int Rotate(vector<int>& a, int x) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] == x)
            return mid;

        // Left half is sorted
        if (a[l] <= a[mid]) {
            if (a[l] <= x && x < a[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        // Right half is sorted
        else {
            if (a[mid] < x && x <= a[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
}
int main(){
    vector<int>  a = {4,5,6,7,0,1,2};
    cout<<Rotate(a,0);
}