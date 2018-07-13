#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//���鼯

//find-union 
class uf{
	private:
		vector<int> id; //��ʾȺ 
		vector<int> sz; //Ⱥ��Ԫ�ظ��� 
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
       return M.size()-c;//��c�����ںϣ�ʣ�µĶ���û�б��ںϵģ����ǹ����� 
}

    int findCircleNum(vector<vector<int>>& M) {
        	if(M.size()==0||M[0].size()==0)return 0;
	int m=M.size(),n=M[0].size();
	vector<int> root(n,0);//���� 
	int i,j;
	int res=n;
	for(i=0;i<n;i++)root[i]=i;//������Լ�Ϊ1��
    for(i=0;i<m;i++){
    	for(j=i+1;j<n;j++){
    		if(M[i][j]){
    			int p=i;
    			//�ҵ�i���ĸ���� 
    			while(p!=root[p])p=root[root[p]];  
    			int q=j;
    			//�ҵ�j���ĸ���� 
    			while(q!=root[q])q=root[root[q]]; 
    			if(p==q){
    				continue;
    			}else{
    				//��һ�¸��¸���㣬�Ǹ���㣡��������ԭ��� 
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
