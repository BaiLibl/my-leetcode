#include<iostream>
#include<vector> 
#include<string>
using namespace std;


class solution{
	public:
		
		//��������֮���໥���ã�������������Ȼû�а취��ʹ��ǰ���� 
bool pyramidTransition(string bottom, vector<string>& allowed) {
    return DFS(bottom, 0, allowed, ""); //����bottomΪ�ף�nextbottom�����ɵ���һ��
}	
bool DFS(string &bottom, int start, vector<string>& allowed, string nextbottom){
	if(nextbottom.length()==bottom.length()-1){
		//˵����һ��������ϣ�����һ��Ϊ��׼
		if(nextbottom.length()==1)return true;
		return DFS(nextbottom,0,allowed,""); 
	}
	int i,j;
	for(i=start;i<bottom.length();i++){
		for(j=0;j<allowed.size();j++){
			string s=allowed[j];
			if(s[0]==bottom[i]&&s[1]==bottom[i+1]){
			if(DFS(bottom,i+1,allowed,nextbottom+s[2]))return true;
			//ֻҪ��һ�����������ȷ�Ϳ��� 
			}
		}	
	} 
	return false;      
}


};



int main(){
	return 0;
} 
