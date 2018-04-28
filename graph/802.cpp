#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
��һֱ���������K�Ƕ��٣��ѵ����������޲��ܽ�����ͼ���޻�����˼������
safe������Ҫ��Ľ��
cycle���γɻ��Ľ�� ���ڻ�·
visited�� ��·���� �ý���Ƿ��Ѿ������� 
 
*/

//k���ڽ����������޻�����˼ 

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
