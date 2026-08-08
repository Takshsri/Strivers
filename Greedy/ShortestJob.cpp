#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ShortestJob(vector<int>& a){
    sort(a.begin(),a.end());
    int time=0;
    int waitingTime =0;
    for(int i=0;i<a.size();i++){
        waitingTime += time;
        time += a[i];
        cout<<waitingTime<<" "<<time<<endl;
        
    }
    return waitingTime/a.size();
}

int main(){      
    vector<int> a = {1,4,3,7,2};
    cout<<ShortestJob(a);
}