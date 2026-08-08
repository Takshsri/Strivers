#include<iostream>
#include<vector>
using namespace std;
int Index(vector<int>& a){
    int total =0;
    for(int i : a){
        total+=i;
    }
    int leftSum = 0;
    for(int i=0;i<a.size();i++){
        total -= a[i];
        if(leftSum == total){
            return i;
        }
        leftSum+= a[i];
    }
    return -1;
}
int main(){
    vector<int> a = {1,7,3,6,5,6};
    cout<<Index(a);
}