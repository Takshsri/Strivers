#include<iostream>
#include<vector>
using namespace std;
void CycleSort(vector<int>& a){
    int i=0;
    int n= a.size();
    while(i<n){
        int correctNum = a[i] -1;
        if(a[i]!=a[correctNum]){
            swap(a[i],a[correctNum]);
        }
        else{
            i++;
        }
    }
}
int main(){
    vector<int> a = {2,3,4,1};
    for(int i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    CycleSort(a);
    for(int i : a){
        cout<<i<<" ";
    }
}