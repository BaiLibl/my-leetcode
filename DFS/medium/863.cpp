#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//二叉树转化为无向图，用dfs查找路径 
   map<int,vector<int>> graph;
    vector<int> ans;
    //构造图
    void dfs(TreeNode* root){
        if(root==NULL)return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    void dfs2(int t,int visited,int dep,int k){
        if(dep==k){
            ans.push_back(t);
        }
        int i,u;
        for(i=0;i<graph[t].size();i++){
            u=graph[t][i];
            if(u==visited)continue;
            dfs2(u,t,dep+1,k);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root==NULL||target==NULL)return vector<int>();
        dfs(root);//构造图的连接矩阵
        dfs2(target->val,-1,0,K);
        return ans;
    }
int main(){
	return 0;
} 
