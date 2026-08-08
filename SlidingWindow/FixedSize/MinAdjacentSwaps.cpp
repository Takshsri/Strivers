#include<iostream>
#include<vector>
using namespace std;

int MinSwaps(vector<int>& a){
    int count =0;
    for(int i : a){
        if(i== 1) count++;
    }
    if(count ==1 || count ==0){
        return 0;
    }
    int oneCount =0;
    for(int i=0;i<count;i++){
        if(a[i]==1){
            oneCount++;
        }
    }
    int minSwaps = count- oneCount;
    for(int i=count;i<a.size();i++){
        if(a[i]==1){
            oneCount++;
        }
        if(a[i-count]==1) oneCount--;
        minSwaps = min(minSwaps,count-oneCount);
    }
    return minSwaps;
}

int main(){
    vector<int> a = {1,0,1,0,1};
    cout<<MinSwaps(a);
} 