#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> PreviousSmaller(vector<int>& a){
    int n = a.size();
    vector<int> left(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = -1;
        }
        else{
            left[i] = st.top();
        }
        st.push(i);
    }
    return left;
}

vector<int> nextSmaller(vector<int>& a){
    int n = a.size();
    vector<int> res(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            res[i] = n;
        }
        else{ 
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}
int large(vector<int>& a){
    vector<int> left = PreviousSmaller(a);
    vector<int> right = nextSmaller(a);
    int ans = 0;
    for(int i=0;i<a.size();i++){
        int width = right[i]-left[i]-1;
        int area = a[i]*width;
        ans = max(ans,area);
    }
    return ans;
    

}
int main(){
    vector<int> a = {2,1,5,6,2,3};
    cout<<large(a);

}