#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
using namespace std;



vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, vector<pair<string, double> > > h;
        for(int i = 0; i < equations.size(); i++){
            h[equations[i].first].push_back({equations[i].second, values[i]});
            if(values[i] != 0) h[equations[i].second].push_back({equations[i].first, 1 / values[i]});
        }
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string> s;
            double temp = help(queries[i].first, queries[i].second, s, h);
            if(temp != 0.0) ans.push_back(temp); //0.0标志没有找到这条路 
            else ans.push_back(-1.0);
        }
        return ans;
        
    }
    //dfs
    //当前结点，目的地，s字符串，图信息 
    // s存储已经被访问过的结点 
    double help(string cur, string dst, unordered_set<string>& s, unordered_map<string, vector<pair<string, double>>>& h){
        //图中没有这个源结点或者没有目的结点 
		if(h.find(cur) == h.end() || h.find(dst) == h.end()) return -1.0; //prevent from the input doesn't exist in h
        //源结点和目标结点一致 
		if(cur == dst) return 1;
		//s标记是否读过这个结点 
        if(s.find(cur) != s.end()) return 0.0; //0.0标志没找到这条路径 
        s.insert(cur);                         //we can use 0.0 to determine it
        for(int i = 0; i < h[cur].size(); i++){
            double sub_ans = help(h[cur][i].first, dst, s, h);
            if(sub_ans != 0.0) return h[cur][i].second * sub_ans;
        }
        //回溯结点 
        s.erase(cur);
        return 0.0;
    }
int main(){
	return 0;
}
