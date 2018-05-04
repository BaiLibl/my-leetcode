#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int singleNumber(vector<int>& nums) {
	if(nums.size()==0)return -1;
	sort(nums.begin(),nums.end());
	int i=0;
	while(i<nums.size()){
		if(i+1>=nums.size()||nums[i]!=nums[i+1])return nums[i];
		i+=2;
	}        
	return -1;
}
/*
		int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= A[i];
        }
        return sum;
*/
int main(){
	return 0;
}
