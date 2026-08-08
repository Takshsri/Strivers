#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string Reverse(string str){
    int l =0;
    int r= str.size()-1;
    cout<<str<<endl;
    while(l<=r){
        swap(str[l],str[r]);
        l++;
        r--;
    }
    cout<<str<<endl;
    return str;
}
int main() {
    int n,pos;
    cin>>n>>pos;
    string str="";
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        str+=ch;
    }
    str = Reverse(str);
    cout<<endl;
    cout<<str[pos-1];
    return 0;
}