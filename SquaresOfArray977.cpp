#include<iostream>
#include<vector>
using namespace std;
vector<int> Squares(vector<int>& a){
    int n = a.size();
    int i =0;
    int j = n-1;
    vector<int> temp(n);
    n-=1;
    while(i<=j){
        int leftsq = a[i]* a[i];
        int rightsq = a[j]* a[j];
        if(leftsq >= rightsq){
            temp[n--] = leftsq;
            i++;
        }
        else{
            temp[n--] = rightsq;
            j--;
        }
    }
    return temp;
}
int main(){
    vector<int> a = {-4,-2,-0,3,9};
    vector<int> res = Squares(a);
    for(int i : res){
        cout<<i<<" ";
    }
}