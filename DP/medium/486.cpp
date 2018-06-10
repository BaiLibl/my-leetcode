#include<iostream>
#include<vector>
using namespace std;

int res;
//每一个动态规划背后都一个递归算法 
int dfs(vector<int>& nums,int i,int j){
     if(i==j){
     	return nums[i];
     }else{
     	return max(nums[i]-dfs(nums,i+1,j),nums[j]-dfs(nums,i,j-1));
     } 
}

bool PredictTheWinner(vector<int>& nums) {
	return dfs(nums,0,nums.size()-1)>=0;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(5);
	a.push_back(233);
	a.push_back(7);
	cout<<PredictTheWinner(a)<<endl;
	return 0;
}
