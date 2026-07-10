#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Negative(vector<int>& a,int k){
    int n = a.size();
    if(k>n) return {};
    queue<int> q;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(a[i]<0){
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

vector<int> CountNegatives(vector<int>& a,int k){
    vector<int> res;
    int count =0;
    for(int i=0;i<k;i++){
        if(a[i]<0){
            count++;
        }
    }
    res.push_back(count);
    for(int i=k;i<a.size();i++){
        if(a[i]<0){
            count++;
        }
        if(a[i-k]<0){
            count--;
        }
        res.push_back(count);
    }
    return res;
}
int main(){
    vector<int> a = {12,-1,-7,3,4,-15,9,8,2};
    vector<int> res = CountNegatives(a,3);
    for(int i : res){
        cout<<i<<" "; 
    }
}