#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Decode(string s,int i ,string curr){
    if(i==s.size()){
        cout<<curr<<endl;
        return;
    }
    if(s[i]=='0') return;
    int one = s[i]-'0';
    char ch = 'a'+one-1;
    Decode(s,i+1,curr+ch);
    if(i+1<s.size()){
        int two = (s[i]-'0')*10 + (s[i+1]-'0');
        if(two>=10 && two<=26){
            char ch = 'a'+two-1;
            Decode(s,i+2,curr+ch);
        }
    }
}

int main(){
    string s = "223";
    Decode(s,0,"");
}