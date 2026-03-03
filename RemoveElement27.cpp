#include<iostream>
#include<vector>
using namespace std;
int  remove(vector<int>& a,int val){
    int i=0;
    for(int j=0;j<a.size();j++){
        if(a[j]!=val){
            a[i]= a[j];
            i++;
        }
    }

     return i;
    
}
int main(){
    vector<int> a = {3,2,2,3};
    int n = remove(a,3);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   
}