#include<iostream>
#include<vector>
using namespace std;
vector<int> Union(vector<int>& a,vector<int>& b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0,j=0;
    vector<int> res;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(res.size() ==0 || res.back()!=a[i]){
                res.push_back(a[i]);
            }
            i++;
        }
        else{
            if(res.size() ==0 || res.back()!=b[j]){
                res.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(res.size() ==0 || res.back()!=a[i]){
            res.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(res.size() ==0 || res.back()!=b[j]){
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
}
int main(){
    vector<int> a= {1,1,2,3,4,5};
    vector<int> b = {1,2,3,8};
    vector<int> unionArray = Union(a,b);
    for(int i : unionArray){
        cout<<i<<" ";
    }
}