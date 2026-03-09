#include<iostream>
#include<vector>
using namespace std;
vector<int> Mismatch(vector<int>& a){
    int i=0;
    int n = a.size();
    while(i<n){
        int currIdx = a[i]-1;
        if(a[i]!=a[currIdx]){
            swap(a[i],a[currIdx]);
        }
        else{
            i++;
        }
    } 
    vector<int> res;
    for(int i=0;i<n;i++){
        if(i+1!=a[i]){
            res.push_back(i+1);
            res.push_back(a[i]);

            break;
        }
    }
    return res;
}
int main(){
    vector<int> a = {1,2,3,3,5};
    vector<int> res = Mismatch(a);
    for(int i : res){
        cout<<i<<" ";

    }
}