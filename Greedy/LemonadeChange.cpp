#include<iostream>
#include<vector>
using namespace std;

bool Lemonade(vector<int>& a){
    int fice=0,ten =0,twenty = 0;
    for(int i : a){
        if(i==5){
            fice++;
        }
        else if(i==10){
            if(fice){
                fice--; 
                ten++;
            }
            else{
                return false;
            }
            
        }
        else{
            if(fice && ten){
                ten -= 1;
                fice-= 1;
            }
            else if(fice >=3){
                fice -= 3;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> a = {5,5,10,10,20};
    cout<<Lemonade(a);
}