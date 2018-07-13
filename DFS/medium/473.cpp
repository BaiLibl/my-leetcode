#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(vector<int>& nums,vector<int>& side,int pos,int sum){
	if(pos==nums.size()){
		if(side[0]==sum&&side[1]==sum&&side[1]==sum){
			return true;
		}else{
			return false;
		}
	}
	int i;
	for(i=0;i<4;i++){
		if(side[i]+nums[pos]<=sum){
			side[i]+=nums[pos];
			if(dfs(nums,side,pos+1,sum))return true;
			side[i]-=nums[pos];
		}
	}
	return false;
	
}

bool makesquare(vector<int>& nums) {
	if(nums.size()==0)return false;
	int sum=0,len=0;
	int i,j,maxlen=nums[0];
	vector<int> side(4,0);
	for(i=0;i<nums.size();i++){
		sum+=nums[i];
		maxlen=max(maxlen,nums[i]);
	}
	if(sum%4!=0||maxlen>(sum/4)){
		return false;
	}else{
		len=sum/4;
	}
	sort(nums.begin(),nums.end(),greater<int>());
	return dfs(nums,side,0,len);
	
    
}

int main(){
	return 0;
}
