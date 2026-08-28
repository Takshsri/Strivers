#include<iostream>
#include<vector>
using namespace std;
void FCFS(vector<int>& at,vector<int> bt){
    int n = at.size();
    vector<int> ct(n);
    vector<int> tat(n);
    vector<int> wt(n);
    int time =0;
    double avgTat = 0.0;
    double avgWT=0.0;
    for(int i=0;i<n;i++){
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i]-at[i];
        wt[i] = tat[i]-bt[i];
        avgTat += (double)tat[i];
        avgWT += (double) wt[i];

    }
    for(int i=0;i<n;i++){
        cout<<ct[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<tat[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<wt[i]<<" ";
    }
    cout<<endl;
    cout<<avgTat/n<<endl;
     cout<<avgWT/n<<endl;
      
}
int main(){
    vector<int> at =  {0,1,2,3};
    vector<int> bt = {6,4,2,3};
    FCFS(at,bt);
}