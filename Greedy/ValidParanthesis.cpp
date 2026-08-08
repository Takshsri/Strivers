#include<iostream>
#include<vector>
using namespace std;

bool ValidParanthesis(string s){
    int minOpen = 0,maxOpen =0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            minOpen++;
            maxOpen++;
        }
        else if(s[i]==')'){ 
            minOpen--;
            maxOpen--;
        }
        else if(s[i]=='*'){
            maxOpen++;
            minOpen--;
        }

        if(maxOpen<0){
            return false;
        }
        if(minOpen<0){
            minOpen =0;
        }
    }
    return (minOpen==0);
}

int main(){
    string s= "(*))";
    cout<<ValidParanthesis(s);
}