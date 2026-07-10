// Find K Consecutive Elements with Maximum Product

// Instead of sum, calculate product.


#include<iostream>
#include<vector>
using namespace std;
int MaxProd(vector<int>& a,int k){
    int maxProd = 1;
    int CurrProd = 1;
    int st=0;
    for(int i=0;i<k;i++){
        CurrProd *= a[i];

    }
    maxProd = CurrProd;
    for(int i=k;i<a.size();i++){
        CurrProd = (CurrProd * a[i])/a[i-k];
        if(CurrProd>maxProd){
            maxProd = CurrProd;
            st = i-k+1;
        }
    }
    for(int i=st;i<st+k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return maxProd;
}
int main(){
    vector<int> a = {2, 5, 3, 1, 4, 6};
    cout<<MaxProd(a,3);
}