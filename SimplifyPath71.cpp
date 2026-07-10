#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string path;
    getline(cin,path);
    stringstream ss(path);
    string token;
    stack<string> st;
    while(getline(ss,token,'/')){
        if(token == "" || token == ".") continue;
        if(token == ".."){
            if(!st.empty()){
                st.pop();
            }
        }else{
                st.push(token);
            }
        }
    vector<string> res;
    while(!st.empty()){
        cout<<st.top()<<" ";
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    for(string str: res){
        cout<<str<<"/";
    }

    
}