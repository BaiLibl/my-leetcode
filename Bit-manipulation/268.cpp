#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
	int i;
	if(nums.size()==0) return 0;
	if(nums.size()!=nums[nums.size()-1]) return nums.size();
	for(i=0;i<nums.size();i++){
		if(i!=nums[i]) return i;
	}
}

/*
int n=nums.size();
int ans=n;
for(int i=0;i<n;i++)ans^=i^nums[i];
return ans;
*/ 

int main(){
	return 0;
}
