//Given 2 strings s and t and we shuffling one letter from t and add one other letter to t and after that 
//we have to find the extra letetr
//This question is also know as Find the Difference b/w 2 strings

#include<iostream>
#include<string>
using namespace std;
char Diff(string s1,string s2){
    char ans = 0;
    for(char ch : s1){
        ans ^= ch;
    }
    for(char ch : s2){
        ans ^= ch;
    }
    return ans;
}
int main(){
    string str1 = "abcd";
    string str2 = "abcde";
    cout<<Diff(str1,str2);
}