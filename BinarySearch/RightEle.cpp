#include<iostream>
#include<vector>
using namespace std;
vector<int> Right(vector<int>& a){
    int n = a.size();
    vector<int> res(n);
    res[n-1] = -1;
    int maxi = a[n-1];
    for(int i=n-2;i>=0;i--){
        res[i] = maxi;
        if(a[i]>maxi){
            maxi = a[i];
        }
        
        
    }
    
    return res;
    
}
int main(){
    vector<int> a = {23 ,4,5,7,3};
    vector<int> res = Right(a);
    for(int i : res){
        cout<<i<<" ";
    }
}