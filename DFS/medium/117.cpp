#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//记录每层的结点，从右往左遍历 
void dfs(int k, TreeLinkNode *root, vector<TreeLinkNode*>& arr) {
    if(root==NULL)return;
    root->next=arr[k];
    arr[k]=root;
    dfs(k+1,root->right,arr);
    dfs(k+1,root->left,arr); 
}
int depth(TreeLinkNode* root,int k){
    if(root==NULL)return k;
    return max(depth(root->left,k+1),depth(root->right,k+1));
}
void connect(TreeLinkNode *root) {
    if(root==NULL)return;
    vector<TreeLinkNode*> arr;
    int d=depth(root,0);
    for(int i=0;i<d;i++)//先计算层数 
    {
        arr.push_back(NULL);
    }
    dfs(0,root,arr);
    
}
void connect(TreeLinkNode *root) {
	if(root==NULL)return;
	TreeLinkNode* dummy = new TreeLinkNode(0);
    TreeLinkNode* pre = dummy;
    //一层一层遍历 
    while(root != NULL) {
        if(root->left != NULL) {
            pre->next = root->left;
            pre = pre->next;
        }
        if(root->right != NULL) {
            pre->next = root->right;
            pre = pre->next;
        }
        root = root->next;
        // done with the search of current level
        if(root == NULL) {
            root = dummy->next;
            pre = dummy;
            dummy->next = NULL;
        }
    }     
    
}


int main(){
	return 0;
}
