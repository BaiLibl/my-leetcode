#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
vector<int> res;
void dfs(vector<int>& nums,int j, int i){
	if(i>=nums.size())return;
	if(nums[i]>nums[j]){
		res[i]++;
		//int m;
		dfs(nums,i,i+1);
	}
}
*/
//�����ж����ͬ���ȵ��Ӵ� 
//��̬�滮
//res[]:��¼nums[i]��β�����鳤��
//cou[]:��¼num[i]��β���������
//    
int findNumberOfLIS(vector<int>& nums) {
	int n=nums.size();
	if(n==0)return 0;
	vector<int> res(n,1);
	vector<int> cou(n,1);
	int i,j;
	int maxlen =1;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(nums[j]<nums[i]){
				if(res[j]+1>res[i]){
					res[i]=res[j]+1;
					cou[i]=cou[j];	//���鳤�����ӣ����������� 
				}else if(res[j]+1==res[i]){
					cou[i]+=cou[j]; //���鳤�Ȳ��䣬���������� 
				}

			}
		}
		maxlen = max(maxlen,res[i]); //���ֵ�������ظ������ 
	}
	int m = 0;
	for(i=0;i<n;i++){
	 if(maxlen == res[i]) m+=cou[i];
	}
	return m;
	//���ظ���Ƭ�Σ���Ҫ������ظ�Ƭ�Σ�����һ������
	/* 
	int m=1;
	i=1;
	sort(res.begin(),res.end());
	while(i<n){
		while(res[i]==res[i-1]&&i<n){
			m++;
			i++;
		}
		i++;
	}
	return m;
	*/
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(3);
	a.push_back(5);
	cout<<findNumberOfLIS(a)<<endl;
	return 0;
}
