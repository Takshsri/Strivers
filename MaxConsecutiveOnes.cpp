#include<iostream>
#include<vector>
using namespace std;

int MaxConsecutiveOnes(vector<int>& a){
    int maxCount = 0;
    int count = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]==1){
            count++;
            maxCount = max(maxCount,count);

        }else{
            count = 0;
        }
    }
    return maxCount;
}

int main(){
    vector<int> a = {1,1,0,0,1,1,1,9,1,1,1,1,1};
    cout<<MaxConsecutiveOnes(a);
}