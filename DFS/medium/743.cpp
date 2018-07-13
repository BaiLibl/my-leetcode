#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
单源最短路径问题：
Bellman Ford
从k点出发到达其他各个顶点的最短距离 
*/

int networkDelayTime(vector<vector<int> >& times, int N, int K) {
	vector<int> res(N+1,INT_MAX); //假设每个点不可达
	res[0]=0;//0点不计算
	res[K]=0;
	int i,j;
	for(j=0;j<N;j++){
		for(i=0;i<times.size();i++){
			vector<int> t=times[i];
			int u=t[0],v=t[1],w=t[2];
			if(res[u]!=INT_MAX&&res[u]+w<res[v]){
				res[v]=w+res[u];
			}
		} 	
	}	
	int s=0;
	for(i=1;i<=N;i++){
		if(res[i]==INT_MAX)return -1;
		s=max(s,res[i]);//求最长的路径 
	}
	return s;    
}

int main(){
	return 0;
} 
