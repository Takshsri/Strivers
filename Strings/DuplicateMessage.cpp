#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<bool> MessageDuplicate(vector<int>& time, vector<string>& msgs, int k) {
    int n = time.size();
    vector<bool> res(n);

    unordered_map<string, int> lastSeen;

    for (int i = 0; i < n; i++) {

        if (lastSeen.find(msgs[i]) == lastSeen.end()) {
            // First occurrence
            res[i] = true;
        }
        else {
            int prevTime = lastSeen[msgs[i]];

            if (time[i] - prevTime < k) {
                // Duplicate within k seconds
                res[i] = false;
            }
            else { 
                // Not a duplicate
                res[i] = true;
            }
        }

        // Update latest occurrence
        lastSeen[msgs[i]] = time[i];
    }

    return res;
}
int main(){
    vector<int> time = {1,2,3,8,10};
    vector<string> msg = {"hi","hello","hi","hi","hello"};
    int k = 5;
    vector<bool> res = MessageDuplicate(time,msg,k);
    for(bool i : res){
        cout<<i<<" ";
    }
}