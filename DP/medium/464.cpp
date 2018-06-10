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
	//max��󲻳���20�������һ��������ʾ��ѡ�����ڶ���������Ϊ1
	for(i=1;i<=max;i++){
		int mask=(1<<i);
		//(mask&visit) ==0˵��visit��ûѡ�����i
		//���ʣ��С��i ����ֱ������
		//canWin(total-i,mask|visit)==false��ʾ�Է����ˣ���iλ�Ǳ����������� 
		if((mask&visit)==0&&(total<=i||(canWin(total-i,mask|visit)==false))){
			m[visit]=true;
			return true;
		}
	}
	m[visit]=false;
	return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
	max=maxChoosableInteger;//����֣����int max��������ȷ����Ϊ����maxû�и�ֵ
	int total= desiredTotal; 
	if(max>=total)return true;
	if((1+max)*max/2<total)return false;//����ʹ����ͬ�����֣�ȫ������������������˭ҲӮ����
	return canWin(total,0); //��total �£�ѡ��0 
}
 
};
/*
//������������� 
int max;
map<int,bool> m;

bool canWin(int total,int visit){
	if(m.find(visit)!=m.end()) return m[visit];
	int i,mask;
	//max��󲻳���20�������һ��������ʾ��ѡ�����ڶ���������Ϊ1
	for(i=1;i<=max;i++){
		mask=(1<<i);
		//(mask&visit) ==0˵��visit��ûѡ�����i
		//���ʣ��С��i ����ֱ������
		//canWin(total-i,mask|visit)==false��ʾ�Է����ˣ���iλ�Ǳ����������� 
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
	if((1+max)*max/2>total)return false;//����ʹ����ͬ�����֣�ȫ������������������˭ҲӮ����
	return canWin(total,0); //��total �£�ѡ��0 
}

*/

int main(){
	return 0;
}
