#include<iostream>
#include<string>
#include<vector>
using namespace std;
string Compressor(string str){
    int count = 1;
    string ans= "";
    for(int i=1;i<=str.size();i++){
        if(i<str.size() && str[i]==str[i-1]){
            count++;
        }   
        else{
           ans+=str[i-1];
           ans+=to_string(count);
           count = 1;
        }
    }
    return ans;
    
}
int main(){
    string str = "aaabbcc";
    cout<<Compressor(str);
}