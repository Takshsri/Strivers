#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Leader(vector<int>& a){
    int n = a.size();
    vector<int> res;

    int maxi = a[n-1];
    res.push_back(maxi);

    for(int i = n-2; i >= 0; i--){
        if(a[i] > maxi){
            maxi = a[i];
            res.push_back(maxi);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> a = {10,22,12,3,0,6};
    vector<int> res = Leader(a);

    for(int i : res){
        cout << i << " ";
    } 
}