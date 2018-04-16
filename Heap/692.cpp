#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
    
vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string>   res;
	if(words.size()==0||k<=0)return res;
	map<string,int> mp;
	map<int,vector<string> > mp2;
	int i,j;
	for(i=0;i<words.size();i++){
		string s=words[i];
		mp[s]++;
	}
    map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
    	vector<string> tmp = mp2[it->second];
    	string s=it->first;
    	tmp.push_back(s);
    	mp2[it->second]=tmp;
    }
    map<int,vector<string> >::iterator it2;
    vector<string> kk;
    for(it2=mp2.begin();it2!=mp2.end();it2++){
    	vector<string> tmp=it2->second;
    	for(i=tmp.size()-1;i>=0;i--)kk.push_back(tmp[i]);
    }
    //cout<<endl;
    
    //for(i=0;i<kk.size();i++)cout<<kk[i]<<' ';
    j=0;
    i=kk.size()-1;
    while(j<k&&i>=0){
    	res.push_back(kk[i]);
    	i--;
    	j++;
    }
    //for(i=0;i<res.size();i++)cout<<res[i]<<' ';
    
	return res;
}

int main(){
	vector<string> words;
	words.push_back("i");
	words.push_back("love");
	words.push_back("leetcode");
	words.push_back("i");
	words.push_back("love");
	words.push_back("codind");
	vector<string> a=topKFrequent(words,2);
 	return 0;
}
