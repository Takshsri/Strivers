#include<iostream>
#include<vector>
using namespace std;
void Rearrange(vector<int>& a){
   
    int i=0,j=1,n= a.size();
    while(i<n && j<n){
        if(a[i]>0 && i%2==0){
            i+=2;
        }
        else if(a[j]<0 && j%2!=0){
            j+=2;
        }
        else {
            swap(a[i],a[j]);
            i+=2;
            j+=2;
        }
    }
    
}//for abive problem we cant preserve the order of the elemenents by swapping them 
//in order to presrve the order we use some other method

vector<int> RearrangePreserve(vector<int>& a){
    int n = a.size();
    vector<int> ans(n);
    int posIdx = 0;
    int negIdx = 1;
    for(int i : a){
        if(i>0){
            ans[posIdx] = i;
            posIdx += 2;
        }
        else{
            ans[negIdx] = i;
            negIdx += 2;
        }
    }
    return ans;

}
int main(){
    vector<int> a = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    // Rearrange(a);
    // for(int i: a){
    //     cout<<i<<" ";
    // }
    cout<<endl;
    vector<int> b = RearrangePreserve(a);
    for(int i: b){
        cout<<i<<" ";
    }
    return 0;
}