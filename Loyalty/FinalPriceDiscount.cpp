#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> FinalPrice(vector<int>& a){
    int n = a.size();
    vector<int> res = a;
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&& a[st.top()]>=a[i]){
            res[st.top()] = a[st.top()] - a[i];
            st.pop();
        }
        
        st.push(i);

    }
    return res;
}
int main(){
    vector<int> a = {8,4,6,2,3};
    vector<int> res = FinalPrice(a);
    for(int i : res){
        cout<<i<<" ";
    }   
}