#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kthSmallest(vector< vector<int> >& matrix, int k) {
	if(matrix.size()==0)return 0;
	vector<int> res;
	int i,j;
	for(i=0;i<matrix.size();i++){
		for(j=0;j<matrix[i].size();j++){
			res.push_back(matrix[i][j]);
		}
	}        
	sort(res.begin(),res.end());
	return res[k-1];
    
}

int main(){
	return 0;
}
