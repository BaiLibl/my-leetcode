#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//并查集

//find-union 
class uf{
	private:
		vector<int> id; //所示群 
		vector<int> sz; //群里元素个数 
		int c;
	public:
		uf(int n):c(n){
			int i;
			for(i=0;i<n;i++){
				id.push_back(i);
				sz.push_back(1);
			}
		}
		bool connected(int p,int q){
			return find(p)==find(q);
		}
		int find(int p){
			while(p!=id[p]){
				id[p] = id[id[p]];
				p = id[p];
			}
			return p;
		}
		void un(int p,int q){//union
			int i=find(p);
			int j=find(q);
			if(i==j)return;
			if(sz[i]<sz[j]){
				id[i]=j;
				sz[j]+=sz[i];
			}else{
				id[j]=i;
				sz[i]+=sz[j];
			}
			c--;
		}
};  
int findCircleNum(vector< vector<int> >& M) {
	
	  uf uff(M.size());
	  int c=0;
      int i;
      for(i=0;i<M.size();i++){
      	for(j=i;j<M[i].size();j++){
      	      if(M[i][j]==1&&!uff.connected(i,j)){
      	      	c++;
      	      	uff.un(i,j);
      	      }	
      	}
      } 
      //return c ;
       return M.size()-c;//有c个被融合，剩下的都是没有被融合的，就是孤立的 
}

    int findCircleNum(vector<vector<int>>& M) {
        	if(M.size()==0||M[0].size()==0)return 0;
	int m=M.size(),n=M[0].size();
	vector<int> root(n,0);//方阵 
	int i,j;
	int res=n;
	for(i=0;i<n;i++)root[i]=i;//起初是自己为1家
    for(i=0;i<m;i++){
    	for(j=i+1;j<n;j++){
    		if(M[i][j]){
    			int p=i;
    			//找到i结点的父结点 
    			while(p!=root[p])p=root[root[p]];  
    			int q=j;
    			//找到j结点的父结点 
    			while(q!=root[q])q=root[root[q]]; 
    			if(p==q){
    				continue;
    			}else{
    				//不一致更新父结点，是父结点！！！不是原结点 
    				root[q]=p;
    				res--;
    			}
    		} 
    	}
    }
    return res;
    }

/*
//dfs
void dfs(vector< vector<int> >& M,vector<int>& visited,int pos){
	int i;
	for(i=0;i<M.size();i++){
		if(M[pos][i]==1&&visited[i]==0){
			visited[i]=1;
			dfs(M,visited,i);
		}
	}

}

int findCircleNum(vector< vector<int> >& M) {
	if(M.size()==0)return 0;
	vector<int> visited=vector<int>(M.size(),0);
	int c = 0;
	int i;
	for(i=0;i<M.size();i++){
		if(visited[i]==0){
			dfs(M,visited,i);
			c++;
		}
	}
	return c;
}
*/
int main(){
	return 0;
}
