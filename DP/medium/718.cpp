#include<iostream>
#include<vector>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
	int alen = A.size(),blen = B.size();
	if(alen==0||blen==0)return 0;
	vector< vector<int> > dp(alen,vector<int>(blen,0));
	int i,j;
	for(i=0;i<alen&&i<blen;i++){
		if(A[i]==B[i])dp[i][i]=1;
	} 
	int res=0; 
	      
	for(i=0;i<alen;i++){
		for(j=0;j<blen;j++){
			if(i==0){
				if(A[0]==B[j])dp[0][j]=1;
			}else if(j==0){
				if(A[i]==B[0])dp[i][0]=1;
			} else if(A[i]==B[j]){
				dp[i][j]=dp[i-1][j-1]+1;	
			}
			res=max(res,dp[i][j]);
			cout<<i<<' '<<j<<' '<<res<<endl;
		}
	}
	return res;
	
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	vector<int> b;
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	b.push_back(1);
	cout<<findLength(a,b)<<endl;
	return 0;
}
