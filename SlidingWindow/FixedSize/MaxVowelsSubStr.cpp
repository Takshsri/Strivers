// Maximum Number of Vowels in a Substring of Length K

// LeetCode 1456


#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool isVowel(char ch){
    if(ch=='a'|| ch=='e'||ch=='i'|| ch=='o'||ch=='u'){
        return true;
    }
    return false;
    
    }
int MaxCount(string str,int k){
    int maxCount = 0;
    int currCount =0;
    for(int i=0;i<k;i++){
        if(isVowel(str[i])){
            currCount++;
        }
    }
    maxCount = currCount;
    for(int i=k;i<str.size();i++){
        if(isVowel(str[i])){
            currCount++;
        }
        if(isVowel(str[i-k])){
            currCount--;
        }
        maxCount = max(maxCount,currCount);
    }
    return maxCount;
}
int main(){
    string str = "aeiousrewsdf";
    cout<<MaxCount(str,4);
}