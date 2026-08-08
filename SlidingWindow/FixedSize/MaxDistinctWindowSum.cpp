#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int Distinct(vector<int>& a,int k){
   unordered_map<int,int> freq;
   long long sum =0;
   long long ans = 0;
   for(int i=0;i<k;i++){
    sum += a[i];
    freq[a[i]]++;
   }
   if(freq.size()==k){
    ans = sum;
   }
   for(int i=k;i<a.size();i++){
    sum -= a[i-k];
    freq[a[i-k]]--;
    if(freq[a[i-k]]==0){
        freq.erase(a[i-k]);
    }  

    sum += a[i];
    freq[a[i]]++;
    if(freq.size()==k){
        ans = max(ans,sum);
    }
   }
   return ans;
}
int main(){
    vector<int> a = {1,5,4,2,9,9,9};
    int k = 3;
    cout<<Distinct(a,k);
}