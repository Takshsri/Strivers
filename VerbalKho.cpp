#include<iostream>
#include<vector>
using namespace std;
int KhoKho(vector<int>& a,int n){
    int IncorrectCount=0;
   
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            IncorrectCount+=1;
        }
       

    }
    return (IncorrectCount == 0 ) ? 0 : IncorrectCount+1;
}
int main(){
    int n;
    cout<<"Enter No.of Friends:";
    cin>>n;
    vector<int> Msg(n) ;
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter Msg:";
        cin>>num;
        Msg[i] = num;
    }
    cout<<KhoKho(Msg,n);
}