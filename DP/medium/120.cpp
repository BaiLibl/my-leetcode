#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int minimumTotal(vector< vector<int> >& triangle) {
	if(triangle.size()==0)return 0;      
	int n = triangle.size(); 
	vector< vector<int> > res(n,vector<int>(n,0)); 
	int i,j;
	//最后一行 
	for(i=0;i<n;i++){
		res[n-1][i]=triangle[n-1][i];
	}
	for(i=n-2;i>=0;i--){
		for(j=0;j<=i;j++){
			res[i][j]=min(res[i+1][j],res[i+1][j+1])+triangle[i][j];
		}
	} 
	return res[0][0]; 
	
}

int main(){
	
	return 0;
}
