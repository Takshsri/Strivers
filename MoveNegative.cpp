#include<iostream>
#include<vector>
using namespace std;
vector<int> move(vector<int>& nums){
 int i=0,j= nums.size()-1;
    while(i<=j){
        if(nums[i]<0){
            i++;
        }
        else if(nums[j]>=0){
            j--;
        }
        else{
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
    }
    return nums;

}
int main(){
    vector<int> a = {1, 2, -3, 4, -4, -5};
    vector<int> res = move(a);
    for(int i : res){
        cout<<i<<" ";
    }
}