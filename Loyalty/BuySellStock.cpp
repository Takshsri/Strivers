#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int BestTime(vector<int>& a){
    int maxi = 0;
    int currMin = a[0];
    int n = a.size();
    for(int i=1;i<n;i++){
        
        if(a[i]<currMin){
            currMin = a[i];
        } 
        maxi = max(maxi,a[i]-currMin);
    }
    return maxi;
}
int main(){
    vector<int> a = {9, 8, 7, 6, 5};
    cout<<BestTime(a);
}