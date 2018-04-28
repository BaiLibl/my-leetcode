#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
BFS ˼·���ͳ����ĴӸ��ڵ���� BFS ��ͬ�������Ҷ�ӽڵ㿪ʼ���� BFS��
������ȣ�������������Ϊ 1 �Ľڵ㼴��Ҷ�ӽڵ㡣
�Ҹ߶���С�Ľڵ㣬����������Ҷ�ӽڵ���Զ�Ľڵ㣬Ҳ���������ĵĽڵ㡣
�������ĵĽڵ��˼·�ܼ򵥣�
    ÿ��ȥ����ǰͼ������Ҷ�ӽڵ㣬�ظ��˲���ֱ��ֻʣ�����ĸ���
��Ҷ�ӽ��һ��һ����룬ֱ�����������ĵĵ㣺ֻ��1���������� 
*/
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<vector<int> > graph(n,vector<int>());
    vector<int> counters(n, 0);
    int i,j; 
    for (i=0;i<edges.size();i++) {
    	pair<int,int> e=edges[i];
        graph[e.first].push_back(e.second);
        graph[e.second].push_back(e.first);
        counters[e.first]++;
        counters[e.second]++;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
    	if (counters[i] <= 1) {//����Ҷ�ӽ�� 
        	q.push(i);
        }
    }
    while (n > 2) { //ֱ��ͼ�л���������� 
        int num_leafs = q.size(); //��һ���ж��ٸ�Ҷ�ӽ�� 
        n -= num_leafs;
    	for (i = 0; i < num_leafs; ++i) { //ֻ����һ��num_leafsҶ�ӽ�㴦�� 
            int node = q.front();
            q.pop();
            for (j=0;j<graph[node].size();j++) {
            	int neighbor=graph[node][j];
            	counters[neighbor]--;
                if (counters[neighbor] == 1) {
                        q.push(neighbor);
                }
            }
        }
    }
    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
