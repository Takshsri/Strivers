#include<iostream>
#include<string>
using namespace std;

int DeciBinary(string s){
    char sum=0;
    for(char ch : s){
        if(ch>sum ) {
            sum = ch;
        }
    }
    return sum-'0';
}
int main(){
    string s = "321";
    cout<<"Answer for the is:"<<DeciBinary(s);
}