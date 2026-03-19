#include<iostream>
#include<vector>
using namespace std;
int Target(vector<int>& a,int target){
    int sum = 0;
    int start = 0;

    int mini = INT_MAX;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        while(sum >= target){
            mini = min(mini,i-start+1);
            sum -= a[start++];
        }
    }
    
    return (mini == INT_MAX)? 0: mini;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    cout<<Target(a,12);
}