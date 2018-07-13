#include<iostream>
#include<vector>
using namespace std;



int shoppingOffers(vector<int>& price, vector< vector<int> >& special, vector<int>& needs) {
	  int n=needs.size();
	  int i,j;
	  int all=0;//别忘记初始化 
	  for(i=0;i<n;i++)all+=price[i]*needs[i];//剩余需要 
	  for(i=0;i<special.size();i++){
			bool flag=true;
			vector<int> nextneeds=needs;
			for(j=0;j<n;j++){
				if(needs[j]-special[i][j]<0){
					flag=false;
					break;
				}else{
					nextneeds[j]=nextneeds[j]-special[i][j];
				}
			}
			if(flag){
				all = min(all,special[i].back()+shoppingOffers(price,special,nextneeds));
			}
	  }
	  return all;      
}

int main(){
	return 0;
}
