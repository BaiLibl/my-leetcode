#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	vector<int> res;
	if(nums1.empty()||nums2.empty()){
		return res;
	}
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	int i,j;
	/*
	for(i=0;i<nums1.size();i++){
		cout<<nums1[i]<<' ';
	}
	cout<<endl;
	for(i=0;i<nums2.size();i++){
		cout<<nums2[i]<<' ';
	}
	cout<<endl;
	*/
	i=0;
	j=0;
	while(i<nums1.size()&&j<nums2.size()){
		//cout<<i<<' '<<nums1[i]<<' '<<j<<' '<<nums2[j]<<endl;
		if(nums1[i]==nums2[j]){
			res.push_back(nums1[i]);
			i++;
			j++;
		}
		if(nums1[i]>nums2[j]){
			j++;
		}
		if(nums1[i]<nums2[j]){
			i++;
		}
	}
	return res;
}

int main(){
	vector<int> n1,n2;
	n1.push_back(1);
	n1.push_back(2);
	n1.push_back(2);
	n1.push_back(2);
	n1.push_back(1);
	n2.push_back(2);
	n2.push_back(2);
	vector<int> a=intersection(n1,n2);
	int i=0;
	for(i=0;i<a.size();i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
