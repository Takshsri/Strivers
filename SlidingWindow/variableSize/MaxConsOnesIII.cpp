#include<iostream>
#include<vector>
using namespace std;
int MaxOnes(vector<int>& a,int k){
    int freq =0;
    int CountZero= 0;
    int left =0;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            CountZero++;
        }
        while(CountZero >k){
            if(a[left]==0){
                CountZero--;
            }
            left++; 
        }
        freq = max(freq,i-left+1);

    }
    return freq;
}
int main(){
    vector<int> a = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout<<MaxOnes(a,2);
}