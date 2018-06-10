#include<iostream>
#include<vector>
#include<map>
using namespace std;

//���εı������� 
bool canPartition(vector<int>& nums) {
	if(nums.size()==0)return false;
	int i,j,sum=0;
	for(i=0;i<nums.size();i++)sum+=nums[i];
	if(sum%2!=0)return false;
	vector< vector<int> > dp(nums.size()+1,vector<int>(sum/2+1,0));
	//dp[i][j]�ڱ�������Ϊj������£�����ǰi����Ʒ�����õ���������� 
	sum=sum/2;
	for(i=nums[0];i<=sum;i++){
		dp[0][i]=nums[0];//ֻ�ܷ���nums[0] 
	}
	for(i=1;i<nums.size();i++){
		for(j=nums[i];j<=sum;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
			//ǰi����Ʒ���������Ϊj�ı��������Ž⡣
		}
	}
	if(dp[nums.size()-1][sum]==sum)return true;
	return false;
}

int main(){
	return 0;
} 
