#include<iostream>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites){
	int i,j;
	if(numCourses==0)return vector<int>();
	vector<int> ind(numCourses,0);
	vector< vector<int> > graph(numCourses,vector<int>());
	for(i=0;i<prerequisites.size();i++){
		graph[prerequisites[i].first].push_back(prerequisites[i].second);
		ind[prerequisites[i].second]++;
	}
	queue<int> qu;
	vector<int> res;
	for(i=0;i<numCourses;i++){
		if(ind[i]==0)qu.push(i);
	}
	while(!qu.empty()){
		int cur=qu.front();
		qu.pop();
		res.push_back(cur);
		for(i=0;i<graph[cur].size();i++){
			ind[graph[cur][i]]--;
			if(ind[graph[cur][i]]==0)qu.push(graph[cur][i]);
		}
	}
	for(i=0;i<numCourses;i++){
		if(ind[i]!=0)return vector<int>();
	}
        i=0;
	j=res.size()-1;
	while(i<j){
		int tmp=res[i];
		res[i]=res[j];
		res[j]=tmp;
		i++;
		j--;
	}
    return res;
}

int main(){
	return 0;
}
