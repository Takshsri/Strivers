#include<iostream>
#include<vector>
using namespace std;
void dnf(vector<int>& a){
   int low =0,mid =0,high = a.size()-1;
   while(mid<=high){
    if(a[mid]==0){
        swap(a[mid],a[low]);
        low++;
        mid++;
    }
    else if(a[mid]==1){
        mid++;
    }
    else{
        swap(a[mid],a[high]);
        high--;
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