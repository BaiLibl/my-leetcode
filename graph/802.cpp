#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
我一直不明白这个K是多少，难道就是在有限步能结束，图中无环的意思？？？
safe：满足要求的结点
cycle：形成环的结点 存在环路
visited： 该路径上 该结点是否已经被访问 
 
*/

//k步内结束，就是无环的意思 

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int> safe;
        set<int> cycle;
        set<int> visited;
        int i;
        for(i=0;i<graph.size();i++){
            dfs(graph,safe,cycle,visited,i);
        }
        return vector<int>(safe.begin(),safe.end());
    }
    bool dfs(vector<vector<int>>& g,set<int>& s,set<int>& c,set<int>& v,int i){
        if(c.count(i)||v.count(i))return false;
        if(s.count(i))return true;
        int j;
        v.insert(i);
        for(j=0;j<g[i].size();j++){
            if(!dfs(g,s,c,v,g[i][j])){
                v.erase(i);
                c.insert(i);
                return false;
            }
        }
        v.erase(i);
        s.insert(i);
        return true;
    }
int main(){
	return 0;
}
