#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str = "ramya";
    vector<int> freq(26,0);
    for(int i=0;i<str.size();i++){
        freq[str[i]-'a']++;
        

    }
    for(int i=0;i<freq.size();i++){
        if(freq[i]>0){
            cout<<char(i+'a')<<" "<<freq[i]<<endl;
            
        }5
    }
    
}