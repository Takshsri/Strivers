#include<iostream>
#include<vector>
using namespace std;
int LargestEle(vector<int>& a){
    if(a.empty()) return 0;
    int maxi = a[0];
    if(a.size() == 1) return maxi;
    
    for(int i=1;i<a.size();i++){
        if(a[i]>maxi){
            maxi = a[i];
        }
    }
    return maxi;
}
int main(){
    vector<int> a = {4,5,6,7,23,4};
    cout<<LargestEle(a);
}