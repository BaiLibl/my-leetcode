#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s, string t) {
	if(s.length()!=t.length())
		return false;
	vector<int> hash1(26,0);
	vector<int> hash2(26,0);
	int i;
	for(i=0;i<s.length();i++){
		hash1[s[i]-'a']++;
		hash2[t[i]-'a']++;
	}
	if(hash1==hash2){
		return true;
	}else{
		return false;
	}
}

int main(){
	string s="anagram",p="angram";
	cout<<isAnagram(s,p)<<endl;
	return 0;
}
