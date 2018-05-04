#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<sstream>
using namespace std;

vector<int> hour = {1, 2, 4, 8}, minute = {1, 2, 4, 8, 16, 32};

void dfs(vector<string>& res,int h,int m,int num,int cur){
	if(num==0){
		res.push_back(to_string(h)+(m < 10 ?  ":0" : ":")+to_string(m));
		//分钟要特殊处理 
		return;
	}
	int i;
	for(i=cur;i<hour.size()+minute.size();i++){
		if(i<hour.size()){
			h+=hour[i];
			if(h<12){
				dfs(res,h,m,num-1,i+1);//如果小时可以增加小时 
			}
			h-=hour[i];
		}else{
			m+=minute[i-hour.size()];
			if(m<60){
				dfs(res,h,m,num-1,i+1);//如果分钟可以增加分钟 
			}
			m-=minute[i-hour.size()];
		}
		
	}
}

vector<string> readBinaryWatch(int num) {
	if(num>8)return vector<string>();
    vector<string> res;
    dfs(res, 0,0, num, 0);
    return res;
}
 /*   
    void helper(vector<string>& res, pair<int, int> time, int num, int start_point) {
        if (num == 0) {
            res.push_back(to_string(time.first) +  (time.second < 10 ?  ":0" : ":") + to_string(time.second));
            return;
        }
        for (int i = start_point; i < hour.size() + minute.size(); i ++)
            if (i < hour.size()) {    
                time.first += hour[i];
                if (time.first < 12)     helper(res, time, num - 1, i + 1);     // "hour" should be less than 12.
                time.first -= hour[i];
            } else {     
                time.second += minute[i - hour.size()];
                if (time.second < 60)    helper(res, time, num - 1, i + 1);     // "minute" should be less than 60.
                time.second -= minute[i - hour.size()];
            }
    } 
*/
//搜索空间有限12*60
 
//感觉戴着这变态手表的也只有IT人士了吧，一群黑色乌鸦飘过~~
vector<string> readBinaryWatch2(int num) {
	vector<string> times;
    for (int i = 0; i < 12; i++) {
		bitset<4> h((size_t) i); //bitset<n> h ，声明n 位二进制 
		//把int类型强制转换成bitset类型 
		for (int j = 0; j < 60; j++) {
			bitset<6> m((size_t) j);
			stringstream s1,s2;
			s1<<i;
			s2<<j;
 			if (h.count() + m.count() == num)//count()1位个数，size()总个数 
				times.push_back(s1.str() + (j < 10? ":0": ":") +s2.str());
				s1.clear();
				s2.clear();
            }
        }
        return times;	
} 
int main(){
	return 0;
}
