#include<iostream>
#include<vector>
using namespace std;
int RainWater(vector<int>& a){
    int water =0;
    int left = 0;
    int right = a.size()-1;
    int leftMax = 0;
    int rightMax = 0;
    while(left < right){
        if(a[left]<a[right]){
            if(a[left]>=leftMax){
                leftMax = a[left];
            }
            else{
                water += leftMax - a[left];
            }
            left++;
        }
        else{  
            if(a[right]>=rightMax){
                rightMax = a[right];
            }
            else{
                water += rightMax - a[right];
            }
            right--;
        }
    }
    return water;
}
int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<RainWater(a);
}