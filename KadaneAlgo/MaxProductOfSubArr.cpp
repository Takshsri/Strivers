#include<iostream>
#include<vector>
using namespace std;
//Maximun Product subArray 
//given an array of integers negative,posotive and zero choose any subset  of the elements to get max posssible product
//using kadanes Algorithm 
int main(){
    vector<int> a = {-1,-2,-3,4};
    int maxProd = a[0];
    int minProd = a[0];
    int ans = a[0];
   
    for(int i=1;i<a.size();i++){
        if(a[i]<0){
            swap(minProd,maxProd);
        }
        maxProd = max(a[i],maxProd*a[i]);
        minProd = min(a[i],minProd*a[i]);

        ans = max(ans,maxProd);
       
        

    }
    cout<<ans;
}