#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool validAnagram(string s1,string s2){
    if(s1.size()!=s2.size()) return false;
    vector<int> res(26,0);
    for(int i=0;i<s1.size();i++){
        res[s1[i]-'a']++;
        res[s2[i]-'a']--;
    }
    for(int i : res){
        if(i!=0){
            return false;
        }
    }
    return true;
}
int main(){
    string str1 ,str2;
    cout<<"Enter String 1";
    cin>>str1;
    cout<<"Enter String 2";
    cin>>str2;
    if(validAnagram(str1,str2)){
        cout<<"Both are having Same Characters";
    }
    else{
        cout<<"Not Anagrams";
    }

}