#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int start = 0;
    for(int i=0;i<=str.size();i++){
        if(i==str.size() || str[i]==' '){
            reverse(str.begin()+start,str.begin()+i);
            start = i+1;
        }
    }
    cout<<str;
}