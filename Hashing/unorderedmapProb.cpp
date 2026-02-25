#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    vector<int> arr = {1,45,1,23,5,45,23,5,7,23};
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++; 
    }

    string str = "ramyasrinivivas";
    unordered_map<char,int> mp2;
    for(int i=0;i<str.size();i++){
        mp2[str[i]]++;
    }
    //cout<<endl<<"Numbers:"<<endl;
    // for(auto it : mp){
    //     cout<<it.first<<" : "<<it.second<<"\t";
    // }
    // cout<<endl<<"Chars:"<<endl;
    // for(auto it : mp2){
    //     cout<<it.first<<" : "<<it.second<<"\t";
    //}
   int maxFreq = INT_MIN;
   int minFreq = INT_MAX;
   int maxEle,minEle;
   for(auto it : mp){
    if(it.second > maxFreq){
        maxFreq = it.second;
        maxEle = it.first;
    }

    if(it.second < minFreq){
        minFreq = it.second;
        minEle = it.first;
    }
   }
   cout<< "Max nd Min Freq Elements :"<<endl;
   cout<<maxEle<<" " <<maxFreq<<endl;

   cout<<minEle<<" " <<minFreq<<endl;

//max and min characetrr freq 
    maxFreq = INT_MIN;
    minFreq = INT_MAX;
    char maxChar,minChar;
    for(auto it : mp2){
        if(it.second > maxFreq){
        maxFreq = it.second;
        maxChar = it.first;
        }

        if(it.second < minFreq){
            minFreq = it.second;
            minChar = it.first;
        }
    }
     cout<< "Max nd Min Freq Char Elements :"<<endl;
    cout<<maxChar<<" " <<maxFreq<<endl;

    cout<<minChar<<" " <<minFreq<<endl;

}