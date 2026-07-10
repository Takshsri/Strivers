#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> Temp(vector<int>& a){
    int n = a.size();
    vector<int> res(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            res[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> a = {73,74,75,71,69,72,76,73};
    vector<int> res = Temp(a);
    for(int i : res){
        cout<<i<<" ";
    }
}