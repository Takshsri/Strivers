#include<iostream>
#include<vector>
using namespace std;
int SecondSm(vector<int>& a){
    int small = INT_MAX;
    int ssmall = -1;
    for(int i=1;i<a.size();i++){
        if(a[i]<small){
            ssmall = small;
            small = a[i];
        }
        else if (a[i]!=small && a[i]<ssmall){
            ssmall = a[i];
        }
    }
    return ssmall;
    
}
int main()
{
    vector<int> a = {34,2,12,45,67,88};
    cout<<SecondSm(a);
}