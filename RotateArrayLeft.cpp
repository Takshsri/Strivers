#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& a,int l,int r){
    while(l<r){
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}
void rotateByD(vector<int>& a,int d){
    int n = a.size();
    reverse(a,0,n-d-1);
    reverse(a,n-d,n-1);
    reverse(a,0,n-1);
}
int main(){
    vector<int> a = {1,2,3,4,5};
    rotateByD(a,2);
    for(int i : a){
        cout<<i<<" ";
    }
}