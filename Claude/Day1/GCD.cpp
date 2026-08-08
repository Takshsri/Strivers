#include<iostream>
#include<vector>
using namespace std;
int GCD(int a,int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
} 
void Pairs1(int a1,int a2,int b1,int b2){
    for(int i=a1+1;i<=a2;i++){
        
        if(GCD(i,i-1)==1){
            cout<<i<<" "<<i+1<<endl;
        }
        i++;

    }
    for(int i=b1+1;i<=b2;i++){
        
        if(GCD(i,i-1)==1){
            cout<<i<<" "<<i+1<<endl;
        }
        i++;

    }
}
int main(){
    int n;
    cin>>n;
    int firstRange,firstLast;
    cin>>firstRange>>firstLast;
    int secondRange,secondLast;
    cin>>secondRange>>secondLast;
    Pairs1(firstRange,firstLast,secondRange,secondLast);\
    cout<<endl<<GCD(4,2);
}