#include<iostream>
#include<map>
using namespace std;


class Solution {
private:
    int max;
    map<int,int> m;
public:
    
bool canWin(int total,int visit){
	if(m.find(visit)!=m.end()) return m[visit];
	int i;
	//max最大不超过20，因此用一个整数表示，选过所在二进制设置为1
	for(i=1;i<=max;i++){
		int mask=(1<<i);
		//(mask&visit) ==0说明visit还没选择则过i
		//如果剩余小于i ，会直接拿走
		//canWin(total-i,mask|visit)==false表示对方输了，但i位是被本方拿走了 
		if((mask&visit)==0&&(total<=i||(canWin(total-i,mask|visit)==false))){
			m[visit]=true;
			return true;
		}
	}
	m[visit]=false;
	return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
	max=maxChoosableInteger;//很奇怪，如果int max，则不能正确，因为外面max没有赋值
	int total= desiredTotal; 
	if(max>=total)return true;
	if((1+max)*max/2<total)return false;//不能使用相同的数字，全部加起来还不够，那谁也赢不了
	return canWin(total,0); //在total 下，选择0 
}
 
};
/*
//遍历了所有情况 
int max;
map<int,bool> m;

bool canWin(int total,int visit){
	if(m.find(visit)!=m.end()) return m[visit];
	int i,mask;
	//max最大不超过20，因此用一个整数表示，选过所在二进制设置为1
	for(i=1;i<=max;i++){
		mask=(1<<i);
		//(mask&visit) ==0说明visit还没选择则过i
		//如果剩余小于i ，会直接拿走
		//canWin(total-i,mask|visit)==false表示对方输了，但i位是被本方拿走了 
		if((mask&visit)==0&&(total<=i||(canWin(total-i,mask|visit)==false))){
			m[visit]=true;
			return true;
		}
	}
	m[visit]=false;
	return false;
	
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
	int max=maxChoosableInteger;
	int total= desiredTotal; 
	if(max>=total)return true;
	if((1+max)*max/2>total)return false;//不能使用相同的数字，全部加起来还不够，那谁也赢不了
	return canWin(total,0); //在total 下，选择0 
}

*/

int main(){
	return 0;
}
