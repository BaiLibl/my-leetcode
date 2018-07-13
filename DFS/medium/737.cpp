#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

bool dfs(map<string,set<string> >& graph,string s1,string s2,set<string>& visited){
	if(s1==s2)return true;
	visited.insert(s1);
	for(const auto& next: graph[s1]){
		if(visited.count(next))continue;
		if(dfs(graph,next,s2,visited))return true;
	}
	return false;
}

bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector< pair<string, string> > pairs) {
	if(words1.size()==0&&words2.size()==0)return true;
	if(words1.size()!=words2.size())return false;
	map<string,set<string> > graph;
	
	int i,j;
	for(i=0;i<pairs.size();i++){
		graph[pairs[i].first].insert(pairs[i].second);
		graph[pairs[i].second].insert(pairs[i].first);
	}      
	vector<int> index=vector<int>(words2.size(),0);
	set<string> visited;
	for(i=0;i<words1.size();i++){
		visited.clear(); //ÅÐ¶ÏiÎ»ÖÃÊÇ·ñÏàËÆ 
		if(!dfs(graph,words1[i],words2[i],visited))return false;
		
	}
	return true;
}

int main(){
	pair<string,string> p;
	vector<string> s1,s2;
	vector< pair<string, string> > pairs;
	p.first="good";
	p.second="well";
	s1.push_back(p.first);
	s2.push_back(p.second);
	pairs.push_back(p);
	p.first="acting";
	p.second="drama";
	pairs.push_back(p);
	s1.push_back(p.first);
	s2.push_back(p.second);
	cout<<areSentencesSimilarTwo(s1,s2,pairs);
	return 0;
}
