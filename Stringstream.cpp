#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
vector<int> parseInts(string str){
    vector<int> res;
    stringstream ss(str);
    int num;
    char comma;
    while(ss>>num){
        res.push_back(num);
        ss>>comma;
    }
    return res;
}
string reverse(string s){
    int l =0,r=s.size()-1;
    while(l<r){
        char ch = s[l];
        s[l] = s[r];
        s[r] = ch;
        l++;
        r--;
    }
    return s;
}
string ParseString(string str){
    stringstream ss(str);
    string res;
    string s;
    char space;
    while(ss>> s){
        
        
        res+=reverse(s);
        res+=" ";
    }
    res.pop_back();
    return res;

}
int main(){
    string str;
    getline(cin,str);
    // vector<int> Integers = parseInts(str);
    // for (int i = 0; i < Integers.size(); i++) {
    //     cout << Integers[i] << "\n";
    // } 
   
    // vector<string> Words = ParseString(str);
    // for(string str : Words){
    //     cout<<str<<" ";
    // }
    cout<<ParseString(str);
    
}