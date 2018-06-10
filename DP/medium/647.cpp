#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool Isplin(string s,int m,int n){
	if(s.length()==1)return true;
	int i,j;
	i=m;
	j=n;
	while(i<j){
		if(s[i]!=s[j])return false;
		i++;
		j--;
	}
	return true;
}

int countSubstrings(string s) {
	int res = 0;
	int n=s.length();
	if(n<=1)return 1;
	vector< vector<int> > dp(n,vector<int>(n,0));
	int i,j;
	for(i=0;i<n;i++){
		res++;//i==j
		for(j=i+1;j<n;j++){ 
			if(s[j]==s[i]&&Isplin(s,i,j))dp[i][j]=1;
			res+=dp[i][j];
		}
	}
	return res;        
}

/*
若字符串长度为奇数，则中心为i
若字符串长度为偶数，则中心是i和i+1，以中心向外扩展，O(N^2) 
*/
/*int countSubstrings(string s) {
	if(s.length()==0) return 0;
	int count = 0;
	for(int i = 0; i < s.length(); i++) {
		count += countPalindromicSubstrings(s, i, i);
		count += countPalindromicSubstrings(s, i, i + 1);
	}
	return count;
}

int countPalindromicSubstrings(string s, int begin, int end) {
	int count = 0;
	while(begin >= 0 && end < s.length() && s[begin == s[end]) {
		count++;
		begin--;
		end++;
	}
	return count;
}
*/



int countSubstrings3(string s) {
	string rs = "#";
	//改造
	for(int i = 0; i < s.length(); i++) rs = rs + s[i] + "#";
	//int[] RL = new int[rs.length()];//半径
	vector<int> RL(rs.length(),0);
	int pos = 0; //记录当前最右端的对称中心 
	int maxRight = 0; //记录当前最右的对称边界 
	int count = 0;
	for(int i = 0; i < rs.length(); i++) {
		if(i < maxRight) {
            RL[i] = min(maxRight - i, RL[2 * pos - i]);
        }
        while(i - RL[i] - 1 >= 0 && i + RL[i] + 1< rs.length() && rs[i - RL[i] - 1] == rs[i + RL[i] + 1]) {
            RL[i]++;
        }
        if(i + RL[i] > maxRight) {
            pos = i;
            maxRight = i + RL[i];
        }
        count += (RL[i] + 1) / 2;
    }
    return count;
}


int countSubstrings2(string s) {
        if(s.length()==0)return 0;
        string rs="#";
        int i,j;
        for(i=0;i<s.length();i++)rs=rs+s[i]+"#";
        int pos=0;
        int maxright=0;
        int count=0;
        vector<int> rl(rs.length(),0);
        for(i=0;i<rs.length();i++){
        	if(i<maxright){
        		rl[i]=min(rl[2*pos-i],maxright-i);	
        	}
            //不小于maxright 
            while(i-rl[i]-1>=0&&i+rl[i]+1<rs.length()&&rs[i-rl[i]-1]==rs[i+rl[i]+1])rl[i]++;
            if(rl[i]+i>maxright){
                pos=i;
                maxright=rl[i]+i;
            }
            //cout<<rl[i]<<' '; 
            count+=(rl[i]+1)/2;
            //cout<<endl;
        }
        return count;
    }
int main(){
	string a="aaaa";
	cout<<countSubstrings2(a)<<endl;
	cout<<countSubstrings3(a)<<endl;
	return 0;
}
