#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	if(prices.size()==0)return 0;
	vector<int> buy(prices.size()+1,0),sell(prices.size()+1,0);
	int i;
	buy[1]=-prices[0];
	for(i=2;i<=prices.size();i++){
		buy[i]=max(buy[i-1],sell[i-2]-prices[i-1]);
		sell[i]=max(sell[i-1],buy[i-1]+prices[i-1]);//ÏÂ±êµ¼ÖÂ 
	}
	return sell[prices.size()]; 
	        
}

int main(){
	return 0;
}
