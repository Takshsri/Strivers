#include<iostream>
#include<vector>
using namespace std;

int Minimum(vector<int>& a){
    int l = 0;
    int r = a.size() - 1;

    while(l < r){
        int mid = l + (r-l)/2;

        if(a[mid] > a[r])
            l = mid + 1;
        else
            r = mid;
    }

    return a[l];
}

int Maximum(vector<int>& a){
    int l = 0;
    int r = a.size() - 1;

    while(l < r){
        int mid = l + (r-l)/2;

        if(a[mid] > a[r])
            l = mid + 1;
        else
            r = mid;
    }

    int minIndex = l;

    // Element before minimum is maximum
    int maxIndex = (minIndex - 1 + a.size()) % a.size();

    return a[maxIndex];
}

int main(){
    vector<int> a = {3,4,5,1,2};

    cout << Minimum(a);
    cout << endl << Maximum(a) << endl;
}