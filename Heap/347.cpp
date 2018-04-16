#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

static bool isless(const pair<int,int>& a,const pair<int,int>& b){
	return a.second>b.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
	if(nums.size()==0)return res;
	int i,j;
	map<int,int> mp;
	for(i=0;i<nums.size();i++){
		mp[nums[i]]++;
	}        
	vector< pair<int,int> > vecmp(mp.begin(),mp.end());
	sort(vecmp.begin(),vecmp.end(),isless);
	i=0;
	while(i<k){
		res.push_back(vecmp[i].first);
		i++;
	}
	//for(i=0;i<res.size();i++)cout<<res[i]<<' ';
	return res;
    
}


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a=topKFrequent(a,3);
	return 0;
}
