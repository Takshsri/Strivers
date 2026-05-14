#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> Detect(vector<int>& a,int n){
    int i=0;
    while(i<n){
        int currIdx = a[i]-1;
        if(a[i]!=a[currIdx] && a[i]<=n){
            swap(a[i],a[currIdx]);
        }
        else{
            i++;
        }
    }

    vector<int> res;
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            res.push_back(a[i]);
        }
    }
    return res;
}
//detect duplicates
bool Duplicates(vector<int>& a){
    unordered_set<int> st;
    for(int i : a){
        if(st.count(i)){
            return true;
        }
        st.insert(i);
    }
    return false;
}
int main(){
    vector<int> a = {1,3,4,5};
    int n = a.size();
    cout<< Duplicates(a);
    
}