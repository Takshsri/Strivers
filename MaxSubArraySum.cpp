#include<iostream>
#include<vector>
using namespace std;
int MaxSubArray(vector<int>& a){
    int sum =0, maxi = INT_MIN;
    int ansstart=-1,ansend = -1,start=0;
    for(int i=0;i<a.size();i++){
        if(sum == 0 ){
            start = i;
        }

        sum += a[i];
        if(sum>maxi){
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if(sum<0){
            sum =0;
        }
    }
    for(int i= ansstart;i<=ansend;i++){
        cout<<a[i]<<" "; 
    }
    cout<<endl;
    return maxi;
}
int main(){
    vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
    cout<<MaxSubArray(a);
}