#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
    private:
             string find(string p,map<string,string>& father){
                 while(p!=father[p]){
                     p=father[p];
                 }
                 return p;
             }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if(accounts.size()==0)return vector<vector<string>>();
        int i,j;
        map<string,string> father;
        map<string,string> ower;
        map<string,set<string>> unions;
        
        //初始化
        for(i=0;i<accounts.size();i++){
            for(j=1;j<accounts[i].size();j++){
                father[accounts[i][j]]=accounts[i][j]; 
                ower[accounts[i][j]]=accounts[i][0];
            }
        }
        //合并
        for(i=0;i<accounts.size();i++){
            string p=find(accounts[i][1],father);
            for(j=2;j<accounts[i].size();j++){
                father[find(accounts[i][j],father)]=p;
            }
        }
        for(i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string p=find(accounts[i][j],father);
                unions[p].insert(accounts[i][j]);
            }
        }
        //把成群的放在一起
        vector<vector<string>> res;
        for(pair<string,set<string>> p:unions){
            vector<string> mails(p.second.begin(),p.second.end());
            mails.insert(mails.begin(),ower[p.first]);
            res.push_back(mails);
        }
    return res;
    }
};
int main(){
	return 0;
}
