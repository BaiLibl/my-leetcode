#include<iostream>
#include<vector>
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
vector<int> findRedundantConnection(vector< vector<int> >& edges) {
      uf uff(1001);
      int i;
      for(i=0;i<edges.size();i++){
      	vector<int> val = edges[i];
      	if(uff.connected(val[0]-1,val[1]-1)){
			return val; 
		}else{
			uff.un(val[0]-1,val[1]-1);
		}
      	
      } 
      return {};
}

int main(){
	return 0;
}
