#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findCheapestPrice2(int n, vector<vector<int> >& flights, int src, int dst, int K) {
    if(flights.size()==0)return -1;
	vector<int> dist(n,INT_MAX);
	vector<int> step(n,0);
	int i,j;
	dist[src]=0;
	int u,v,w;
	K++;
	for(i=0;i<K;i++){
		//cout<<i<<endl;
		vector<int> tmp=dist; //每一步都保存上一步的结果 
		for(j=0;j<flights.size();j++){
			u=flights[j][0];
			v=flights[j][1];
			w=flights[j][2];
			/*if(dist[u]!=INT_MAX&&dist[u]+w<dist[v]){
				dist[v]=w+dist[u];
			}*/
			if(tmp[u]!=INT_MAX&&tmp[u]+w<dist[v]){
				dist[v]=w+tmp[u];
			}
		}
	}      
	return dist[dst]==INT_MAX?-1:dist[dst]; 
}

int main(){
	vector< vector<int> > a;
	vector<int> b1;
	b1.push_back(0);
	b1.push_back(1);
	b1.push_back(1);
	vector<int> b2;
	b2.push_back(0);
	b2.push_back(2);
	b2.push_back(5);
	vector<int> b3;
	b3.push_back(1);
	b3.push_back(2);
	b3.push_back(1);
	vector<int> b4;
	b4.push_back(2);
	b4.push_back(3);
	b4.push_back(1); 
	a.push_back(b1);
	a.push_back(b2);
	a.push_back(b3);
	a.push_back(b4);
	cout<<findCheapestPrice2(4,a,0,3,1)<<endl; 
	return 0;
} 
