#include<iostream>
#include<vector>
using namespace std;
int SecondLar(vector<int>& a){
    int large = a[0];
    int secondLarge = -1;
    for(int i=1;i<a.size();i++){
        if(a[i]>large){
            secondLarge = large ;
            large = a[i];

        }
        else if(a[i]<large && a[i]>secondLarge){
            secondLarge = a[i];
        }
    }
    return secondLarge;
}
int main(){
    vector<int> a = {34,5,2,45,67,5,90};
    cout<<SecondLar(a);
}