#include<iostream>
#include<vector>
using namespace std;
vector<int> Product(vector<int>& a){
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = 1;
    vector<int> suffix(n);
    suffix[n-1] = 1;
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] * a[i-1];

    }
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] * a[i+1];
    }
    vector<int> res(n);
    for(int i=0;i<n;i++){
        res[i] = suffix[i]*prefix[i];
    }
    return res;


}
vector<int> ProductOptimal(vector<int>& a){
    int zeros = 0,idx = -1;
    int prod = 1;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            zeros++;
            idx = i;
        }
        else{
            prod *= a[i];
        }
    }
    vector<int> res(a.size(),0);
    if(zeros==0){
        for(int i=0;i<a.size();i++){
            res[i] = prod/a[i];
        }

    }
    else if(zeros == 1){
        res[idx] = prod;
    }
    return res;
}
int main(){
    vector<int> arr = {-1,-4,5,6,7};
    vector<int> res = Product(arr);
    for(int i : res){
        cout<<i<<" ";
    }
} 