#include<iostream>
#include<vector>
using namespace std;
void dnf(vector<int>& a){
    int low = 0,high= a.size()-1,mid = 0;
    while(mid <= high){
        if(a[mid] == 1){
            swap(a[mid],a[low]);
            mid++,low++;
        }
        else if (a[mid]==2){
            mid++;
        }
        else if(a[mid]==3){
            swap(a[mid],a[high]);
            high --;
        }
    }
}
int main(){
    vector<int> a = {3,1,2,1,2};
    for(int i : a){
        cout<<i<<" ";
    }
    dnf(a);
    cout<<endl;
    for(int i : a){
        cout<<i<<" ";
    }
}