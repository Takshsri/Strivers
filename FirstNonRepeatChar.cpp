#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    //unique character
    string str = "racecar";
//     char ch;
//     for(char c:str){
//         ch ^= c;
//     }
//     cout<<ch;


    unordered_map<char,int> freq;
    for(char ch:str){
        freq[ch]++;
    }
    for(char ch : str){
        if(freq[ch]==1){
            cout<<ch;
        }
    }
}