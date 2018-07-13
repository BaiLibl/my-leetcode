#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root,int p){
	if(root==NULL)return p;
	p++;
	return max(depth(root->left,p),depth(root->right,p));
} 

void findleft(TreeNode* root,int p,int hight,vector<int>& res){
	if(root==NULL||res.size()==1)return;
	p++;
	if(p==hight&&res.size()==0){
		res.push_back(root->val);
	}
	findleft(root->left,p,hight,res);
	findleft(root->right,p,hight,res);
}

int findBottomLeftValue(TreeNode* root) {
	 int hight=depth(root,0);
	 vector<int> res;
	 findleft(root,0,hight,res);
	 return res[0];       
}

int main(){
	return 0;
}
