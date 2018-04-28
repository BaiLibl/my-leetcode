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
            if(temp != 0.0) ans.push_back(temp); //0.0��־û���ҵ�����· 
            else ans.push_back(-1.0);
        }
        return ans;
        
    }
    //dfs
    //��ǰ��㣬Ŀ�ĵأ�s�ַ�����ͼ��Ϣ 
    // s�洢�Ѿ������ʹ��Ľ�� 
    double help(string cur, string dst, unordered_set<string>& s, unordered_map<string, vector<pair<string, double>>>& h){
        //ͼ��û�����Դ������û��Ŀ�Ľ�� 
		if(h.find(cur) == h.end() || h.find(dst) == h.end()) return -1.0; //prevent from the input doesn't exist in h
        //Դ����Ŀ����һ�� 
		if(cur == dst) return 1;
		//s����Ƿ���������� 
        if(s.find(cur) != s.end()) return 0.0; //0.0��־û�ҵ�����·�� 
        s.insert(cur);                         //we can use 0.0 to determine it
        for(int i = 0; i < h[cur].size(); i++){
            double sub_ans = help(h[cur][i].first, dst, s, h);
            if(sub_ans != 0.0) return h[cur][i].second * sub_ans;
        }
        //���ݽ�� 
        s.erase(cur);
        return 0.0;
    }
int main(){
	return 0;
}
