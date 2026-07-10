#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> MaximumSlide(vector<int>& a,int k){
    int n = a.size();
    if(k>n) return {};
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        while(!dq.empty() && a[dq.back()]<=a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            res.push_back(a[dq.front()]);
        }
    }
    return res;
}
int main(){
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    vector<int> res = MaximumSlide(a,3);
    for(int i : res){
        cout<<i<<" ";
    }
}