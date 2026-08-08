#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data{
    int start;
    int end;
    int pos;
};

int Meeting(vector<int>& st, vector<int>& en){

    int n = st.size();

    vector<Data> meet(n);

    for(int i = 0; i < n; i++){
        meet[i].start = st[i];
        meet[i].end = en[i];
        meet[i].pos = i + 1;
    }

    sort(meet.begin(), meet.end(), [](const Data &a, const Data &b){
        return a.end < b.end;
    });

    int cnt = 1;
    int freeTime = meet[0].end;

    for(int i = 1; i < n; i++){
        if(meet[i].start >= freeTime){
            cnt++;
            freeTime = meet[i].end;
        }
    }

    return n-cnt;
}

int main(){

    vector<int> st = {1,3,0,5,8,5};
    vector<int> en = {2,4,6,7,9,9};

    cout << Meeting(st,en);
}