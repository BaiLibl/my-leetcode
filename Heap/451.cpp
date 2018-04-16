#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
 第一反应是利用stl中提供的sort算法实现，这个想法是好的，
 不幸的是，sort算法有个限制，利用sort算法只能对序列容器进行排序，
 就是线性的（如vector，list，deque）。map也是一个集合容器，它里面存储的元素是pair，
 但是它不是线性存储的（前面提过，像红黑树），所以利用sort不能直接和map结合进行排序。需要将map转为vector。
*/
static bool isless(const pair<char,int> l, const pair<char,int> r)  //静态成员函数？？？
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
