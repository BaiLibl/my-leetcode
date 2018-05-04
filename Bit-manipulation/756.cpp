#include<iostream>
#include<vector> 
#include<string>
using namespace std;


class solution{
	public:
		
		//两个函数之间相互调用，必须放在类里，不然没有办法在使用前声明 
bool pyramidTransition(string bottom, vector<string>& allowed) {
    return DFS(bottom, 0, allowed, ""); //在以bottom为底，nextbottom是生成的下一层
}	
bool DFS(string &bottom, int start, vector<string>& allowed, string nextbottom){
	if(nextbottom.length()==bottom.length()-1){
		//说明上一层生成完毕，以这一层为基准
		if(nextbottom.length()==1)return true;
		return DFS(nextbottom,0,allowed,""); 
	}
	int i,j;
	for(i=start;i<bottom.length();i++){
		for(j=0;j<allowed.size();j++){
			string s=allowed[j];
			if(s[0]==bottom[i]&&s[1]==bottom[i+1]){
			if(DFS(bottom,i+1,allowed,nextbottom+s[2]))return true;
			//只要有一种情况返回正确就可以 
			}
		}	
	} 
	return false;      
}


};



int main(){
	return 0;
} 
