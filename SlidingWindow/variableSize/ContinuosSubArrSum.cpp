#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int checkSubArr(vector<int>& nums,int k){
    unordered_map<int,int> map;
        map[0] = -1;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum%k;
            if(map.find(rem)!=map.end()){
                if(i-map[rem]>=2){
                    return true;
                }

            }
            else{
                map[rem] = i;
            }
        }
        return false;

}
int main(){
    vector<int> a = {23,2};
    cout<<checkSubArr(a,13);
}