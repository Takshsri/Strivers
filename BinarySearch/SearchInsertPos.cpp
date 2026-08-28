#include<iostream>
#include<vector>
using namespace std;

int SearchPos(vector<int>& a,int k){
    int l = 0;
    int r = a.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
       
        if(a[mid]>k){
            r = mid-1;
        }
        else {
            l = mid+ 1;
        }
    }
    return l;
}
int main(){
    vector<int> a = {1,2,4,5};
    int k =3;
    cout<<SearchPos(a,k);
}