#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

vector<string> findRepeatedDnaSequences1(string s) {
	vector<string> res;
	if(s.length()<=10)return res;
	int i;
	map<string,int> mp;
	for(i=0;i<=s.length()-10;i++){
		string ss=s.substr(i,10);
		//cout<<ss<<endl;
		mp[ss]++;
	} 
	      
	map<string,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second>1){
			cout<<it->first<<endl;
			res.push_back(it->first);
		}
	}
	return res;
    
}

/*
用一个整数来表示字符串，A-00 C-01 G-10 T-11 
*/
vector<string> findRepeatedDnaSequences(string s){
	vector<string> res;
	map<int,int> mp;
	map<int,int> mp2;
	map<char,int> p;
	p['A']=0;
	p['C']=1;
	p['G']=2;
	p['T']=3; 
 
	int i,v = 0; // Use a sliding window to check every 10-bit substring 
	for (i = 0; i < s.length(); i++) { 
		// 2 bits/char * 10 char = 20 bits so use 0xfffff
		v = (v<<2 | p[s[i]]) & 0xfffff; //计算当前这个字符串对应的数字 
		//cout<<v<<endl;
		if (i < 9) continue; // Check each 10-bit substring
		else { // If first come out duplicates, then add to list 
			//if (mp[v]==2) res.push_back(s.substr(i-9, i+1)); 
			mp[v]++;
			mp2[v]=i;
		} 
	} 
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if(it->second>1){
			res.push_back(s.substr(mp2[it->first]-9, 10)); 
			cout<<	s.substr(mp2[it->first]-9, 10)<<endl;
		}
	} 
	return res; 
}



int main(){
	vector<string> a;
	string s="AAAAAAAAAAA";
	a=findRepeatedDnaSequences(s);
	return 0;
}
