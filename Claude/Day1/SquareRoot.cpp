#include<iostream>
using namespace std;

int Sqrt(int n){
    int l=0,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        long s =(long) mid * mid;
        if(s==n){
            return mid;
        }
        else if(s<n){
            l =mid+1;
            
        }
        else{
            r= mid-1;
        }
        cout<<"L value:"<<l<<endl;
        cout<<"R Value:"<<r<<endl;
        cout<<"mid value:"<<mid<<endl;
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    cout<<Sqrt(n);
}