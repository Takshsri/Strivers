#include<iostream>
#include<iostream>
using namespace std;
int lengthOfLastWord(string s) {
        
    stringstream ss(s);
        vector<string> res;
        string str;

        while (ss >> str) {
            res.push_back(str);
        }

        return res.back().size();
    }

int lengthOfLastWord2(string s) {
        stringstream ss(s);
        string word, last;

        while (ss >> word) {
            last = word;
        }

        return last.size();
    }
int main(){
    string str;
    getline(cin,str);
    int i=str.size()-1;
    while(i>=0 && str[i]==' '){
        i--;
    }
        int len = 0;
        while(i>=0 && str[i]!=' '){
            len++;
            i--;
        }

    cout<<len;
}
