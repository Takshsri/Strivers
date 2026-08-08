#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const vector<int>&a,const vector<int>& b){
    return a[1]<b[1];
}
int Activity(vector<int>& st,vector<int>& ed){
    if(st.size()==1){
        return 1;
    }
    int n = st.size();
    int count = 1;

    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        res.push_back({st[i],ed[i]});
    }
    sort(res.begin(),res.end(),compare);
    int j=0;

    for(int i=1;i<n;i++){
        if(res[i][0]>res[j][1]){
            count++;
            j=i;  
        }
    }

    return count;
}
int main(){
    vector<int> st = {10,12,20};
    vector<int> end = {20,25,30};
    cout<<Activity(st,end);
}