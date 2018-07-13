#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
������ֳ����飬�����ȷ���ĸ�Ӧ�÷ֵ���һ����ã����ܵĻ����ȴ��ţ������ 
*/ 

bool isBipartite(vector<vector<int> >& graph) {
	if(graph.size()==0)return false;
	//if(graph.size()==1)return true;
	set<int> a;
	set<int> b;
	vector<pair<int,int> > list; //������Щ�����жϵı� 
	int i,j;
	int s,d;
	for(i=0;i<graph.size();i++){
		s=i;
		for(j=0;j<graph[i].size();j++){
			if(i==0&&j==0){
				a.insert(0);//��ʼ�� 
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
 bool validColor(vector< vector<int> >& graph,vector<int>& colors,int color,int node){
	    if (colors[node] != -1) {//�Ѿ���ɫ 
            return colors[node] == color;
        }       
        colors[node] = color;
		int i;       
        for (i=0;i<graph[node].size();i++) {
        	int next=graph[node][i];
            if (!validColor(graph, colors, 1 - color, next)) {
                return false;
            }
        }
        return true;
}
//ֻ��0ɫ��1ɫ 
bool isBipartite(vector< vector<int> >& graph){
	int n=graph.size();
	if(n<=1)return true;
	vector<int> color(n,-1);//��δ��ɫ
	int i,j;
	for(i = 0; i < n; i++) {             
            if (color[i] == -1 && !validColor(graph, color, 0, i)) {
                return false;
            }
    }
    return true;
}

int main(){
	return 0;
}
