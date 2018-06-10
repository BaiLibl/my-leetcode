#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
	if(nums.size()==0)return res;
	vector< vector<int> > dp;
	int i,j;
	sort(nums.begin(),nums.end());
	for(i=0;i<nums.size();i++){
		vector<int> tmp;
		tmp.push_back(nums[i]);
		dp.push_back(tmp);
	}
	for(i=1;i<nums.size();i++){
		for(j=i-1;j>=0;j--){
			if(nums[i]%dp[j].back()!=0){
				continue;
			}else if(dp[j].size()+1>dp[i].size()){
				vector<int> tmp= dp[j];
				tmp.push_back(nums[i]);
				dp[i]=tmp;
			}
		}
	}
	for(i=0;i<dp.size();i++){
		if(res.size()<dp[i].size())res=dp[i];
	}
    return res;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(8);
	//a.push_back();
	vector<int> b=largestDivisibleSubset(a);
	int i;
	for(i=0;i<b.size();i++)cout<<b[i]<<' ';
	return 0;
}
