#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
将顶点分成两组，如果能确定哪个应该分到哪一个最好，不能的话就先存着，最后处理 
*/ 

bool isBipartite(vector<vector<int> >& graph) {
	if(graph.size()==0)return false;
	//if(graph.size()==1)return true;
	set<int> a;
	set<int> b;
	vector<pair<int,int> > list; //保存那些不能判断的边 
	int i,j;
	int s,d;
	for(i=0;i<graph.size();i++){
		s=i;
		for(j=0;j<graph[i].size();j++){
			if(i==0&&j==0){
				a.insert(0);//初始化 
			}
			d=graph[i][j];
			if((a.count(s)&&a.count(d))||(b.count(s)&&b.count(d))){
				return false;
			}else if(a.count(s)||b.count(d)){
				a.insert(s);
				b.insert(d);
			}else if(a.count(d)||b.count(s)){
				a.insert(d);
				b.insert(s);
			}else{
				list.push_back({s,d});
			}
		}
	}
	for(i=0;i<list.size();i++){
		s=list[i].first;
		d=list[i].second;
		if((a.count(s)&&a.count(d))||(b.count(s)&&b.count(d))){
			return false;
		}else if(a.count(s)||b.count(d)){
			a.insert(s);
			b.insert(d);
		}else{
			a.insert(d);
			b.insert(s);
		}
	}
	return true;
}

int main(){
	return 0;
}
