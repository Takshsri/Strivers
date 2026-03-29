#include<iostream>
#include<vector>

using namespace std;
int MajorityEle(vector<int>& a){
    int ans = 0;
    int freq =0;
    for(int i=0;i<a.size();i++){
        if(freq==0){
            ans = a[i];
        }
        if(ans == a[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,3};
    cout<<"Majority Element :"<<MajorityEle(arr);
}