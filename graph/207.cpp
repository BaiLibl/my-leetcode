#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
      int i,j;
	if(numCourses==0||prerequisites.size()==0)return true;
	vector<int> ind(numCourses,0);
	vector< vector<int> > graph(numCourses,vector<int>());
	for(i=0;i<prerequisites.size();i++){
		graph[prerequisites[i].first].push_back(prerequisites[i].second);
		ind[prerequisites[i].second]++;
	}
	queue<int> qu;
	for(i=0;i<numCourses;i++){
		if(ind[i]==0)qu.push(i);
	}
	while(!qu.empty()){
		int cur=qu.front();
		qu.pop();
		for(i=0;i<graph[cur].size();i++){
			ind[graph[cur][i]]--;
			if(ind[graph[cur][i]]==0)qu.push(graph[cur][i]);
		}
	}
	for(i=0;i<numCourses;i++){
		if(ind[i]!=0)return false;
	}
    return true;
}

int main(){
	vector< pair<int, int> > a;
	pair<int,int> p;
	p.first=1;
	p.second=0;
	a.push_back(p);
	p.first=1;
	p.second=3;
	a.push_back(p);
	p.first=3;
	p.second=1;
	a.push_back(p);
	p.first=3;
	p.second=2;
	a.push_back(p);
	cout<<canFinish(3,a)<<endl;
	return 0;
}
