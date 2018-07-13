#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//������ת��Ϊ����ͼ����dfs����·�� 
   map<int,vector<int>> graph;
    vector<int> ans;
    //����ͼ
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
        dfs(root);//����ͼ�����Ӿ���
        dfs2(target->val,-1,0,K);
        return ans;
    }
int main(){
	return 0;
} 
