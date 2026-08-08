#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Job(vector<int>& j,vector<int>& p){
    vector<pair<int,int>> jobs;
    for(int i=0;i<j.size();i++){
        jobs.push_back({j[i],p[i]});
    }

    sort(jobs.begin(),jobs.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
    });

    int maxDeadline = 0;
    for(auto job:jobs){
        maxDeadline = max(maxDeadline,job.first);
    }

    vector<int> Schedule(maxDeadline+1,-1);
    int profit = 0;
    for(auto job : jobs){
        int deadline = job.first;
        for(int k = deadline;k>=1;k--){
            if(Schedule[k]==-1){
                Schedule[k]=job.first;
                profit+= job.second;
                break;
            }
        }
    }
    for(int i : Schedule){
        cout<<i<<" ";
    }
    cout<<endl;
    return profit;
    
}
int main(){
     vector<int> j = {1,2,3,2,4};
     vector<int> p = {20,30,40,10,80};
     cout<<Job(j,p);
}

/*
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();

        vector<pair<int,int>> jobs;

        int maxDeadline = 0;

        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

        parent.resize(maxDeadline + 1);

        for(int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int cnt = 0;
        int prof = 0;

        for(auto job : jobs) {

            int p = job.first;
            int d = job.second;

            int availableSlot = find(d);

            if(availableSlot > 0) {
                cnt++;
                prof += p;

                parent[availableSlot] = find(availableSlot - 1);
            }
        }

        return {cnt, prof};
    }
};
*/