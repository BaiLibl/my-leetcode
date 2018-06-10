#include<iostream>
#include<vector>
using namespace std;
/*
bool Isplin(string s){
	if(s.length()==1)return true;
	int i=0;
	int j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j])return false;
		i++;
		j--;
	}
	return true;
}

void dfs(string s, int pos, string tmp, vector<int> &res){
	cout<<' '<<tmp<<endl;
	if(pos==s.length())
		return;
	string cc=tmp+s[pos];
	if(Isplin(cc)){
		//cout<<cc<<endl;
		res[cc.length()]=1;
		dfs(s,pos+1,cc,res);
	}
	
	dfs(s,pos+1,tmp,res);
}

int longestPalindromeSubseq(string s) {
	vector<int> res(s.length()+1,0);
	res[1]=1;
	dfs(s,0,"",res);   
	int i=s.length();
	while(res[i]!=1&&i>=1)i--;
	return i;     
}
*/

//什么时候用dfs,什么时候用DP，傻傻分不清楚，只是在一种方法做不出来时会考虑另一种

int longestPalindromeSubseq(string s) {
	vector< vector<int> > dp(s.length()+1,vector<int>(s.length()+1,0));
	int i;
	int j;
	for(i=0;i<s.length();i++)dp[i][i]=1;
	for(i=s.length()-1;i>=0;i--){
		for(j=i+1;j<s.length();j++){
			if(s[i]==s[j]){
				dp[i][j] = dp[i+1][j-1]+2;	
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			}
		}
	}    
	return dp[0][s.length()-1];
}
int main(){
	string s="aabaa";
	cout<<longestPalindromeSubseq(s)<<endl;
	return 0;
} 
