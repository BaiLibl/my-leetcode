#include<iostream>
#include<vector>
#include<set>
using namespace std;

//暴力AC 
//题目中给定了数字的返回不会超过31,那么最多只能有32位，
//我们用一个从左往右的mask，用来提取数字的前缀，然后将其都存入set中，
//我们用一个变量t，用来验证当前位为1再或上之前结果res，
//看结果和set中的前缀异或之后在不在set中，
//这里用到了一个性质，若a^b=c，那么a=b^c，因为t是我们要验证的当前最大值，
//所以我们遍历set中的数时，和t异或后的结果仍在set中，
//说明两个前缀可以异或出t的值，所以我们更新res为t，继续遍历
int findMaximumXOR(vector<int>& nums) {
    int res =0,mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        set<int> s;
        for (auto& num:nums) {
            s.insert(num & mask);               
        }
        int t = res | (1 << i);
        int count = 0;
        for (auto& prefix:s) {                
                if (s.find(t ^ prefix)!=s.end()) {
                    count++;
                    
                }
                if (count) {
                    res = t;
                    break;
                }
        }
        
    }  
    return res;
};

int main(){
	return 0;
}
