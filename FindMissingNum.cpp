#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Missing(vector<int>& a){
    int n = a.size();
    int sum = (n+1)*(n+2)/2;
    for(int i:a){
        sum -= i;
    }
    return sum;
}
int findFirstPosMissing(vector<int>& a){
    sort(a.begin(),a.end());
    int n = a.size();
    int missingNum = 1;
    for(int i:a){
        if(i<=0) continue;
        if(i==missingNum){
            missingNum++;
        }
        else if (i>missingNum){
            break;
        }
    }
    return missingNum;

}
//optimal Solution
int findFirstPosMissOptimal(vector<int>& a){
    int n = a.size();
    int i=0;
while(i < n){

    if(a[i] > 0 && a[i] <= n){

        int correctNum = a[i] - 1;

        if(a[i] != a[correctNum]){
            swap(a[i], a[correctNum]);
            continue;
        }
    }

    i++;
}
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}
int main(){
    vector<int> a = {1,2,3,4,6};
    cout<<findFirstPosMissOptimal(a);
}