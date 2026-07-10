#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//next smaller element
vector<int> Previous(vector<int>&a){
    stack<int> st;
    int n = a.size();
    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            res[st.top()] = a[i];
            st.pop();
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