#include<iostream>
#include<vector>
using namespace std;

void dfs(vector< vector<int> >& rooms,vector<int>& open,int cur){
	if(cur>=open.size()||!open[cur])return;
	int i,v;
	for(i=0;i<rooms[cur].size();i++){
		v=rooms[cur][i];
		if(!open[v]){
			open[v]=1;
			dfs(rooms,open,v);
		}
	}
}

bool canVisitAllRooms(vector<vector<int> >& rooms) {
	if(rooms.size()<1)return true; //=1 open
	int n=rooms.size();
	vector<int> open(n,0);
	open[0]=1;
	dfs(rooms,open,0);        
	int i=0;
	while(i<n&&open[i])i++;
	      
	return i==n;
}

int main(){
	vector<int> a;
	a.push_back(1);
	vector< vector<int> > b;
	b.push_back(a);
	a[0]=2;
	b.push_back(a);
	a[0]=3;
	b.push_back(a);
	vector<int> c;
	b.push_back(c);
	cout<<canVisitAllRooms(b)<<endl;
	return 0;
}
