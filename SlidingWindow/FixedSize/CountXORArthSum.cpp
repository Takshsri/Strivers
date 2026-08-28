#include<iostream>
#include<vector>
using namespace std;
int ValidSubarrays(vector<int>&a){
    
    int window =0;
    int count =0;
    int left=0;
    for(int i=0;i<a.size();i++){
        while((window & a[i])>0){
            window^=a[left++];
        }
        window |= a[i];
        count += (i-left+1);
    }
    return count;
}
int main(){
    vector<int> a = {2,4,3};
    cout<<ValidSubarrays(a);

}