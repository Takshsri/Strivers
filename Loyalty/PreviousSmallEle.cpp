#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> Previous(vector<int>& a){
    int n = a.size();
    vector<int> res(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i] = a[st.top()];
        }
        st.push(i);
    }
    return res;
}

int main(){
    vector<int> a = {1,6,3};
    vector<int> res = Previous(a);
    for(int i : res){
        cout<<i<<" ";
    }
}