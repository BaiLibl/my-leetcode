#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    if(prices.size()==0)return 0;
	int i,j,k;
	int res=0;
	vector<int> sold(prices.size()+1,0);
	vector<int> hold(prices.size()+1,0);
	hold[0]=-prices[0];
	for(i=1;i<prices.size();i++){
		sold[i]=max(sold[i-1],hold[i-1]+prices[i]-fee);
		//当前手里没有stock：今天的还是昨天的，或者今天卖了增加prices[i] 
		hold[i]=max(hold[i-1],sold[i-1]-prices[i]);
		//当前手里有一个stock：延续昨天的，今天买进了 
	}
	return sold[prices.size()-1];
	
}

int main(){
	vector<int> b;
	b.push_back(1);
	b.push_back(8);
	b.push_back(4);
	b.push_back(9);
	cout<<maxProfit(b,2)<<endl;
	return 0;
}
