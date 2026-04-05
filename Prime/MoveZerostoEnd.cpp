#include<iostream>
#include<vector>
using namespace std;
vector<int> Move(vector<int>& a){
    int i=0,j=0;
    int n= a.size();
    while(i<n){
        if(a[i]==0){
            i++;
        }
        else{
            swap(a[i],a[j]);
            i++;
            j++;
        }
    }
    return a;
}
int main(){
    vector<int> arr = {1,0,3,4,0,2,0};
    vector<int> res = Move(arr);
    for(int i : res){
        cout<<i<<" ";
    }
}