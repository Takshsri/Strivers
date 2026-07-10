#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Triplets(vector<int>& a){
    int n = a.size();
    int count =0;
    for(int i=0;i<n;i++){
        int x=0;
        for(int k=i;k<n;k++){
            x ^= a[k];
            if(x==0){
                count += (k-i);
            }
        }
    }
    return count;
}
int Optimal(vector<int>& a){
    unordered_map<int,int> prefixXor;
    unordered_map<int,int> indexSum;
    int prefix=0,ans=0;
    for(int i=0;i<a.size();i++){
        
    }
}
int main(){
    vector<int> arr = {1, 1, 1, 1, 1};
    cout<<Triplets(arr);
}