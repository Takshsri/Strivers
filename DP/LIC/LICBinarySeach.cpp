#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LIC(vector<int>& a){
    int n = a.size();
    vector<int> temp;
    temp.push_back(a[0]);
    int l =0;
    for(int i=1;i<n;i++){
        if(a[i]>temp.back()){
            temp.push_back(a[i]);
            l++;
        }else{
            int idx = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
            temp[idx]=a[i];
        }
    }
    return l;
}
int main(){
    vector<int> a = {1,7,8,4,5,6,8,-1,9};
    cout<<LIC(a);
}