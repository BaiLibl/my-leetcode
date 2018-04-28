#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
 
map<string,multiset<string> > graph;
vector<string> res;
void dfs(const string& airport){
	string next;
	while(graph[airport].size()!=0){
		next = *graph[airport].begin();
		graph[airport].erase(graph[airport].begin());
		dfs(next);
	}
	res.push_back(airport);
}
vector<string> findItinerary(vector< pair<string, string> > tickets) {
	if(tickets.size()==0)return res;
	int i;
	for(i=0;i<tickets.size();i++){
		graph[tickets[i].first].insert(tickets[i].second);
	}
	string s="JFK";
	dfs(s);
	reverse(res.begin(),res.end());
	
	for(i=0;i<res.size();i++)cout<<res[i]<<' ';
	return res;
    
} 
/*
拓扑排序 
*/
vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> graph;//红黑树排序
		vector<string> itinerary;
		if (tickets.size() == 0){
			return itinerary;
		}
		for (pair<string, string> eachTicket : tickets){
			graph[eachTicket.first].insert(eachTicket.second);
		}
		stack<string> dfs; //这里用栈而不是队列
       // queue<string> dfs;
		dfs.push("JFK");
		while (!dfs.empty()){
			string topAirport = dfs.top();
			if (graph[topAirport].empty()){
                /*
                没有出边，子节点都已经被处理
                */
				itinerary.push_back(topAirport);
				dfs.pop();
			}
			else {
				//还有子节点，选择最小的子节点，并删除该父结点的子节点
                
				dfs.push(*(graph[topAirport].begin()));
				graph[topAirport].erase(graph[topAirport].begin());
			}
		}
		// Reverse the itinerary.
	    reverse(itinerary.begin(), itinerary.end());
		return itinerary;
    }

int main(){
 	pair<string, string> p;
 	p.first="JFK";
 	p.second="KKK";
 	vector< pair<string, string> > t;
 	t.push_back(p);
 	p.first="KKK";
 	p.second="JFK";
 	t.push_back(p);
 	vector<string> a=findItinerary(t);
	return 0;
}
