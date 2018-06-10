#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> a,vector<int> b){
	return a[0]<b[0];   //升序排列，如果改为return a>b，则为降序
}

int findLongestChain(vector< vector<int> >& pairs) {
	int n=pairs.size();
	if(n==0)return 0;
	int i,j;
	//排序 
	//sort(pairs.begin(),pairs.end(),compare);
	sort(pairs.begin(),pairs.end());//直接就是按第一个数排序的 
	vector<int> res(n,1);
	int maxlen=1;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(pairs[i][0]>pairs[j][1]&&res[j]+1>res[i])res[i]=res[j]+1;
		}
		maxlen=max(maxlen,res[i]);
	}        
	return maxlen;
}

/*
区间排序：贪心算法，以右端点作为排序标准 
*/
 static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()<=1)return pairs.size();
	int i,j;
	sort(pairs.begin(),pairs.end(),cmp);        
	int res=1;
	int end=pairs[0][1];
	for(i=1;i<pairs.size();i++){
		if(end<pairs[i][0]){
			res++;
			end=pairs[i][1];
		}
	}
	return res;
}


int main(){
	return 0;
}
