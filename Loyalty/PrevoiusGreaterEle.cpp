#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> PreviousGreater(vector<int>& a){
    int n = a.size();
    vector<int> res(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]){
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
    vector<int> a = {10, 4, 2, 20, 40, 12, 30};
    vector<int> res = PreviousGreater(a);
    for(int i : res){       
        cout<<i<<" ";
    }
}