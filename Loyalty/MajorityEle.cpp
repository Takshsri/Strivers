#include<iostream>
#include<vector>
using namespace std;
int Majority(vector<int>& a){
    int ans = 0, freq =0;
    for(int i=0;i<a.size();i++){
        if(freq ==0 ){
            ans = a[i];
        }
        if(ans == a[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    int cnt1 =0;
    for(int i=0;i<a.size();i++){
        if(a[i]==ans){
            cnt1++;
        }
    }
    return (cnt1> a.size()/2) ? ans:-1;
}
int main(){
    vector<int> a = {1,2,3,2,2};
    cout<<Majority(a);
}