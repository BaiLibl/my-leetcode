#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
	//ÌØÊâÇé¿ö¿¼ÂÇ
	if(nums.size()==0)
		return 0; 
	vector<int> f1(nums.size()+1,0);
	f1[0]=0;
	f1[1]=nums[0];
	int i;
	for(i=1;i<nums.size();i++){
		f1[i+1]=max(f1[i],f1[i-1]+nums[i]);
	}
	return f1[nums.size()];
	
	        
}

int main(){
	vector<int> h;
	h.push_back(1);
	h.push_back(2);
	h.push_back(3);
	h.push_back(4);
	cout<<rob(h)<<endl; 
	return 0;
	
} 
