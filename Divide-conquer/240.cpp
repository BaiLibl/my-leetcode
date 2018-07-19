#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector< vector<int> >& matrix, int target) {
	if(matrix.size()==0||matrix[0].size()==0)return false;
	int m=matrix.size(),n=matrix[0].size();
	/*
	int i,pos;
	for(i=0;i<m;i++){
		pos=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
		if(pos<n&&matrix[i][pos]==target)return true;	
	}    
	return false;
	*/
	int i=0, j=n-1;  
    while(i<m && j>=0) {  
        int x = matrix[i][j];  
        if(target == x) return true;  
        else if(target < x) --j;  
        else ++i;  
    }  
    return false; 
}

int main(){
	vector<int> a;
	a.push_back(-1);
	vector< vector<int> > m;
	m.push_back(a);
	m.push_back(a);
	cout<<searchMatrix(m,0)<<endl;
	return 0;
}
