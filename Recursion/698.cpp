#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(vector<int> &nums,int pos, int n,int k,int target, vector<int>& mem){
	if(pos==n)return true;
	int j;
	int kk = min(k,pos+1);
	for(j=0;j<kk;j++){
		if(mem[j]+nums[pos]>target)
			continue;
		mem[j]+=nums[pos];
		if(dfs(nums,pos+1,n,k,target,mem))return true;
		mem[j]-=nums[pos];
	}
	return false;
	
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
        
    int n = nums.size();
	if(k>n)return false;
	//sort(nums.begin(),nums.end()); 
	//找数组最大值时，尽量用循环来找，不要用sort，会超时  
	int i;
	int sum=0;
    int mmax = nums[0];
	for(i=0;i<n;i++){
        sum+=nums[i];
        mmax = max(mmax,nums[i]);
    }
	int target =sum/k;
	if(sum%k!=0 || mmax>target)return false;
	vector<int> mem(k,0);
	return dfs(nums,0,n,k,target,mem); 
    }
int main(){
	return 0;
}
