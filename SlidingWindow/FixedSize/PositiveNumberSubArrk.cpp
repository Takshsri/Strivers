#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Positives(vector<int>& a,int k){
    int n = a.size();
    if(k>n) return {};
    vector<int> res;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(a[i]>0){
            q.push(i);
        }
        if(i>=k-1){
            while(!q.empty() && q.front()<=i-k){
                q.pop();
            }
            if(q.empty()){
                res.push_back(0);
            }
            else{
                res.push_back(a[q.front()]);
            }
        }
    }
    return res;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> res = Positives(a,3);
    for(int i : res){
        cout<<i<<" ";
    }
}