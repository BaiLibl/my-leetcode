#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Hash table
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	vector<int> res;
	if(nums1.empty()||nums2.empty()){
		return res;
	}
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	int i,j,k=0;
	i=0;
	j=0;
	while(i<nums1.size()&&j<nums2.size()){
		if(nums1[i]==nums2[j]){
			if(k==0||nums1[i]!=res[k-1]){
				res.push_back(nums1[i]);	
				k++;
			}
		}
		if(nums1[i]>nums2[j]){
			j++;
		}else{
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
