#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//拓扑排序
//富有指向贫穷的
//注意比较 quiet[person[x]]<quiet[person[y]] 父结点的比较，而不得当前结点的比较 

vector<int> loudAndRich(vector< vector<int> >& richer, vector<int>& quiet){
	if(quiet.size()==0)return vector<int>();
	
	vector< vector<int> > graph(quiet.size(),vector<int>());
	vector<int> person(quiet.size(),0);
	vector<int> du(quiet.size(),0);
	int i,x,y,j;
	for(i=0;i<quiet.size();i++){
		person[i]=i;//初始化自己	
	}
	if(richer.size()==0)return quiet;
	for(i=0;i<richer.size();i++){
		x=richer[i][0];
		y=richer[i][1];
		du[y]++;
		graph[x].push_back(y);//x->y
	} 
	queue<int> qu;
	for(i=0;i<du.size();i++){
		if(du[i]==0){
			qu.push(i);
			person[i]=i;
		}
	}
	while(!qu.empty()){
		x=qu.front();
		qu.pop();
		for(j=0;j<graph[x].size();j++){
			y=graph[x][j];
			if(quiet[person[x]]<quiet[person[y]]){ //比较person的值 
				person[y]=person[x];
			}
			du[y]--;
			if(du[y]==0)qu.push(y);
		} 
	} 
    return person;  
}

int main(){
	//[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
    //[3,2,5,4,6,1,7,0]
    vector< vector<int> > r;
    vector<int> a(2,0);
    a[0]=1;
    a[1]=0;
    r.push_back(a);
    a[0]=2;
    a[1]=1;
    r.push_back(a);
    a[0]=3;
    a[1]=1;
    r.push_back(a);
    a[0]=3;
    a[1]=7;
    r.push_back(a);
    a[0]=4;
    a[1]=3;
    r.push_back(a);
    a[0]=5;
    a[1]=3;
    r.push_back(a);
    a[0]=6;
    a[1]=3;
    r.push_back(a);
    int x[]={3,2,5,4,6,1,7,0};
    vector<int> v(x,x+sizeof(x)/sizeof(x[0]));
    vector<int> b=loudAndRich(r,v);
    int i;
    for(i=0;i<b.size();i++)cout<<b[i]<<' ';
	return 0;
}
