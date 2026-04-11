#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum =a[0];
    int currSum = a[0];
   
    for(int i=1;i<a.size();i++){
       currSum = max(a[i],a[i]+currSum);
       maxSum = max(maxSum,currSum); 
        
    }
    cout<<maxSum<<" ";
   
}