#include<iostream>
#include<vector>
using namespace std;
int Root(int n){
    int l =1;
    int  r= n;
    while(l<=r){
        int mid = l+(r-l)/2;
        int square = mid*mid;
        if(square==n){
            return mid;
        }
        else if(square>n) {
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return r;

}
int main(){
    int n ;
    cin>>n;
    cout<<Root(n);
}