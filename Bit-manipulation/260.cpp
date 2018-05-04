#include<iostream>
#include<vector>
using namespace std;

//寻找最高位的1 
int findOne(int n){
	int c=0;
	while((n&1)==0){
		n=(n>>1);
		c++; 
	} 
	return c;
}

vector<int> singleNumber(vector<int>& nums){
	if(nums.size()<=2)return nums;
	int i,j;
	int c=0;
	for(i=0;i<nums.size();i++)c=(c^nums[i]);//异或 00-1 11-0 10-1 01-1
	//cout<<c<<endl; 
	int count=findOne(c);
	//cout<<count<<endl;
	c=(1<<count);
	int a=0,b=0;
	for(i=0;i<nums.size();i++){
		if(nums[i]&c){
			a=(a^nums[i]);
		}else{
			b=(b^nums[i]);
		}
	} 
	vector<int> res;
	res.push_back(a);
	res.push_back(b);
	return res;
}

int main(){
	//int a=4;
	//cout<<findOne(a)<<endl;
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	vector<int> res=singleNumber(a);
	cout<<res[0]<<' '<<res[1]<<endl;
	return 0;
}
