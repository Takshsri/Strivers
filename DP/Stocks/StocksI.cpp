#include<iostream>
#include<vector>
using namespace std;
int Profit(vector<int>& a){
    int n = a.size();
    int maxProfit = 0;
    int mini = a[0];
    for(int i=1;i<n;i++){
        if(a[i]<mini){
            mini = a[i];
            
        }
        maxProfit = max(maxProfit,a[i]-mini);
    }
    return maxProfit;

}

int main(){
    vector<int> st={7,6,5,4,3,2,1};
    cout<<Profit(st);
}