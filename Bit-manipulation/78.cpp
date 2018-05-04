#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//一级一级的增加，先是子集个数为i的元素，个数为i+1的元素在个数为i的元素之上进行构造
vector< vector<int> > subsets(vector<int>& nums) {
	vector< vector<int> > res(1,vector<int>());
	//不用排序
	int i,j;
	int pre_size = 0;//pre_size表示每次应该加一个元素的数据。
	//上一次的大小，保存不大于size的子集个数 
	for(i=0;i<nums.size();i++){
		int n = res.size();
		for(j=0;j<n;j++){
			if(i==0||j>=pre_size||nums[i] != nums[i -1]){
				res.push_back(res[j]);
				res.back().push_back(nums[i]); //在已有元素基础上构造新元素再压栈 
			}
		}
		pre_size = n;
	} 
        
    //res.push_back(44);
    return res;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector< vector<int> > b=subsets(a);
	int i,j;
	for(i=0;i<b.size();i++){
		for(j=0;j<b[i].size();j++){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
