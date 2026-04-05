#include<iostream>
#include<vector>
using namespace std;
int SecondSmall(vector<int>& a){
    int firstSmall = INT_MAX;
    int secondSmall =-1;                       //1,56,7,2,45,8
    for(int i=0;i<a.size();i++){
        if(a[i]<firstSmall ){
            secondSmall = firstSmall;
            firstSmall = a[i];
        }
        else if( a[i]>firstSmall && a[i]<secondSmall){
            secondSmall = a[i];
        }
    }
    return secondSmall;
}
int main(){
    vector<int> a = {1,56,45,42,45,8};
    cout<<SecondSmall(a);
}