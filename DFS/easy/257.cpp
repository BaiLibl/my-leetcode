#include<iostream>
#include<vector>
#include<string>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> path;
void getPaths(TreeNode* root,string s){
	
	if(!root)
		return;	
	if(root->left==NULL&&root->right==NULL){
		path.push_back(s);
	}
	if(root->left!=NULL){
		TreeNode* c=root->left;
		stringstream ss; //��Ϊ�ֲ�������ȫ�����׳����⣬����ۼ��ڻ����У����Ǹı� 
		ss<<c->val;
		getPaths(root->left,s+"->"+ss.str());
		ss.clear();
	}
	if(root->right!=NULL){
		TreeNode* c=root->right;
		stringstream ss;
		ss<<c->val;
		getPaths(root->right,s+"->"+ss.str());
		ss.clear();
	}
	return ;
}
vector<string> binaryTreePaths(TreeNode* root) {
	if(!root)
		return path;
	stringstream ss;
	ss<<root->val;
	getPaths(root,ss.str()+"");
	return path;
}
/*
//����������ݹ�����
//�ݹ��������
//�ݹ����� 
vector<string> binaryTreePaths(TreeNode* root) {
    TreeNode* cur=root;
    vector<string> res;
	if(cur==NULL)return res;
	else if(cur->left==NULL&&cur->right==NULL){
		stringstream s;
		string t;
		s<<cur->val;
		s>>t;
		res.push_back(t);
		return res;
	}else{
		stringstream s;
		string t;
		s<<cur->val;
		s>>t;
		if(cur->left){
			vector<string> leftstr=binaryTreePaths(cur->left);
			int i;
			for(i=0;i<leftstr.size();i++){
				res.push_back(t+"->"+leftstr[i]);
			}
		}
		if(cur->right){
			vector<string> rightstr=binaryTreePaths(cur->right);
			int i;
			for(i=0;i<rightstr.size();i++){
				res.push_back(t+"->"+rightstr[i]);
			}
		}
		return res;
	}
}

*/
int main(){
	return 0;
}
