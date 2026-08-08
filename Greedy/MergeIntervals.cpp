#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> Merge(vector<vector<int>>& a){
    if(a.empty()) return {};
    sort(a.begin(),a.end());
    vector<vector<int>> res;

    res.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i][0]<=res.back()[1]){
            res.back()[1] = max(res.back()[1],a[i][1]);
        }
        else{
            res.push_back(a[i]);
        }
    }
    return res;
}
int main(){
    vector<vector<int>>a = {{1,2},{3,4},{2,8},{11,18}};
    vector<vector<int>>res= Merge(a);
    for(int i=0;i<res.size();i++){
        cout<<"[";
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j];
            if(j+1<res[i].size())
                cout<<",";
        }
        cout<<"] ";
    }
}