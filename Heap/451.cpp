#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
 ��һ��Ӧ������stl���ṩ��sort�㷨ʵ�֣�����뷨�Ǻõģ�
 ���ҵ��ǣ�sort�㷨�и����ƣ�����sort�㷨ֻ�ܶ�����������������
 �������Եģ���vector��list��deque����mapҲ��һ������������������洢��Ԫ����pair��
 �������������Դ洢�ģ�ǰ�������������������������sort����ֱ�Ӻ�map��Ͻ���������Ҫ��mapתΪvector��
*/
static bool isless(const pair<char,int> l, const pair<char,int> r)  //��̬��Ա����������
    {
    	return l.second > r.second;
    }
string frequencySort(string s) {    
       if(s.length()<=1)return s;
        map<char,int> mp; //52*2
        int i;
        for(i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector< pair<char, int> > vecmp(mp.begin(), mp.end()); 
        sort(vecmp.begin(),vecmp.end(),isless);
        string str="";
        for(i=0;i<vecmp.size();i++){
        	int fre=vecmp[i].second;
        	string tmp="0";
        	tmp[0]=vecmp[i].first;
        	int j=0;
        	while(j<fre){
        		str+=tmp;
        		j++;
        	}
        }
        return str;  
}
    
int main(){
   	cout<<frequencySort("Aabb")<<endl;
   	return 0;
}
