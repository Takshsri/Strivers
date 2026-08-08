#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int KhoKho(vector<int>& a,int h){

    int l = 1;
    int r = *max_element(a.begin(),a.end());
    int ans = r;
    while(l<=r){
        int mid = l+(r-l)/2;
        long long hours = 0;
        for(int i : a){
            hours += (i+mid-1)/mid;
        }
        if(hours<=h){
            ans = mid;
            r = mid-1;
        
        }
        else{
            l = mid+1;
        }
    }  
    return ans;
}
int main(){
    vector<int> a = {3,6,7,11};
    cout<<KhoKho(a,8);
}