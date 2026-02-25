#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1, 2, 3,1,4,2};
    vector<int> count(12,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    cout<<count[1];
}