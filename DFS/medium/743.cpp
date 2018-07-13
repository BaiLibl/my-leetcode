#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
��Դ���·�����⣺
Bellman Ford
��k������������������������̾��� 
*/

int networkDelayTime(vector<vector<int> >& times, int N, int K) {
	vector<int> res(N+1,INT_MAX); //����ÿ���㲻�ɴ�
	res[0]=0;//0�㲻����
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
		s=max(s,res[i]);//�����·�� 
	}
	return s;    
}

int main(){
	return 0;
} 
