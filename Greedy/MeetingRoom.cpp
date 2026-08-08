#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data{
    int start;
    int end;
    int pos;
};

int Meeting(vector<int>& st, vector<int>& en){

    int n = st.size();

    vector<Data> meet(n);

    for(int i = 0; i < n; i++){
        meet[i].start = st[i];
        meet[i].end = en[i];
        meet[i].pos = i + 1;
    }

    sort(meet.begin(), meet.end(), [](const Data &a, const Data &b){
        return a.end < b.end;
    });

    int cnt = 1;
    int freeTime = meet[0].end;

    for(int i = 1; i < n; i++){
        if(meet[i].start > freeTime){
            cnt++;
            freeTime = meet[i].end;
        }
    }

    return cnt;
}
bool compare(const vector<int>& a,const vector<int>& b){
    return a[1] < b[1];
}
vector<int> meet(vector<int>&st,vector<int>& ed){
    int n = st.size();
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        res.push_back({st[i],ed[i],i+1});
    }
    vector<int> ans ;
    sort(res.begin(),res.end(),compare);
    int j=0;
    ans.push_back(res[0][2]);
    for(int i=1;i<n;i++){
        if(res[i][0]>res[j][1]){
            ans.push_back(res[i][2]);
            j=i;
        }
 
    }
    return ans ;
}
int main(){

    vector<int> st = {1,3,0,5,8,5};
    vector<int> en = {2,4,6,7,9,9};

    vector<int> res = meet(st,en);
    for(int i : res){
        cout<<i<<" ";
    }
}