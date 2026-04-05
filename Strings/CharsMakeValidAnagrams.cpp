//No of Characters to make a valid Anagrams

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int Valid(string s1,string s2){
    unordered_map<char,int>hash;
    for(char ch : s1){
        hash[ch]++;
    }
    for(char ch:s2){
        hash[ch]--;
    }
    int count = 0;
    for(auto & e:hash){
        count += e.second;
    }
    return count;

}

int main(){
    string s1 = "ramya";
    string s2 = "ram";
    cout<<Valid(s1,s2);
}