#include<iostream>
#include<vector>
using namespace std;

void dfs(vector< vector<int> >& image, vector< vector<int> >& visited,int sr, int sc,int p, int newColor){
	int n=image.size();
	int m=image[0].size();
	if(sr<0||sc<0||sr>=n||sc>=m||image[sr][sc]!=p||visited[sr][sc]==1){
		return;
	}else if(image[sr][sc]==p&&visited[sr][sc]==0){
		visited[sr][sc]=1;
		image[sr][sc]=newColor;
		dfs(image,visited,sr+1,sc,p,newColor);
		dfs(image,visited,sr,sc+1,p,newColor);
		dfs(image,visited,sr-1,sc,p,newColor);		
		dfs(image,visited,sr,sc-1,p,newColor);
	}else{
		return;
	}
		
}
vector< vector<int> > floodFill(vector< vector<int> >& image, int sr, int sc, int newColor) {
    int n=image.size();
	int m=image[0].size();
	vector< vector<int> > visited=vector< vector<int> >(n,vector<int>(m,0));
	dfs(image,visited,sr,sc,image[sr][sc],newColor);
	return image;
    
}
/*
//2018-06-20
void dfs(vector<vector<int> >& image,int sr,int sc,int nc,int oldc){
	int n=image.size(),m=image[0].size();
	image[sr][sc]=nc;//保证不会再被遍历 
	int id[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	int i;
	for(i=0;i<4;i++){
		int x=sr+id[i][0];
		int y=sc+id[i][1];
		if(x>=0&&x<n&&y>=0&&y<m){
			if(image[x][y]==oldc)dfs(image,x,y,nc,oldc);
		}
	}
}
vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
	if(image.size()==0||image[0].size()==0)return image;
	int n=image.size(),m=image[0].size();
	if(sr>=n||sr<0||sc>=m||sc<0)return image;
	if(image[sr][sc]==newColor)return image;//如果更新与新值相同则不更新 
	dfs(image,sr,sc,newColor,image[sr][sc]);
	return image;       
}
*/

int main(){
	return 0;
}
