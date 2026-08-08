#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> DailyTemp(vector<int>& a){
    vector<int> res(a.size(),0);
    stack<int> st;
    for(int i=0;i<a.size();i++){
        while(!st.empty() && a[st.top()]<a[i]){
            res[st.top ()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> a = {73,74,75,71,69,72,76 ,73};
    vector<int> res = DailyTemp(a);
    for(int i : res){
        cout<<i<<" ";
    }
}