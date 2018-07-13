#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(vector<int>& nums,set< vector<int> >& res,vector<int>& cur,int pos){
//	if(pos<0||pos>nums.size())return; //pos=i+1=nums.size()还会有一次递归，这时得压入cur 
	if(cur.size()>1)res.insert(cur);
	int i;
	for(i=pos;i<nums.size();i++){
		if(cur.size()==0||cur.back()<=nums[i]){
			cur.push_back(nums[i]);
			dfs(nums,res,cur,i+1);
			cur.pop_back();
		}
	}	
}

vector< vector<int> > findSubsequences(vector<int>& nums) {
    if(nums.size()==0)return vector< vector<int> >();    
    set< vector<int> > res;
    vector<int> temp;
    
  	dfs(nums,res,temp,0);
    return vector< vector<int> >(res.begin(),res.end());
}

int main(){
	return 0;
}

