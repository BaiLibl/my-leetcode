#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
BFS 思路。和常见的从根节点进行 BFS 不同，这里从叶子节点开始进行 BFS。
所有入度（即相连边数）为 1 的节点即是叶子节点。
找高度最小的节点，即找离所有叶子节点最远的节点，也即找最中心的节点。
找最中心的节点的思路很简单：
    每次去掉当前图的所有叶子节点，重复此操作直到只剩下最后的根。
从叶子结点一层一层剥离，直到靠近最中心的点：只有1个或者两个 
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
    	if (counters[i] <= 1) {//加入叶子结点 
        	q.push(i);
        }
    }
    while (n > 2) { //直到图中还有两个结点 
        int num_leafs = q.size(); //这一层有多少个叶子结点 
        n -= num_leafs;
    	for (i = 0; i < num_leafs; ++i) { //只对这一层num_leafs叶子结点处理 
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
