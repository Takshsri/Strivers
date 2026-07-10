#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> NextGreater(vector<int>& a){
    stack<int> st;
    int n = a.size();
    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> a = {2,1,6,7,2};
    vector<int> res = NextGreater(a);
    for(int i : res){
        cout<<i<<" ";
    }
}