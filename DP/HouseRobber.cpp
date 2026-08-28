#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& a,int st,int end){
    int prev = 0;
    int prev1 = 0;
    for(int i=st;i<=end;i++){
        int take = a[i]+prev1;
        int notTake = 0+prev;
        int curr = max(take,notTake);
        prev1 = prev; 
        prev = curr; 
        
    }
    retu rn prev;
}
int HouseRobber(vector<int>& a){
    int n = a.size();
    if(n==1) return a[0];
    int case1 = solve(a,0,n-2);
    int case2 = solve(a,1,n-1); 
    return max(case1,case2);
}
int main(){
    vector<int> a = {2,3,2};
    cout<<HouseRobber(a);
}