#include<iostream>
#include<vector>
using namespace std;

//最高位有几个1 
int countOne(int num) {
    int count = 0;
    while((num&128)!=0){
        count++;
        num=(num<<1);
   }
 	return count>4?-1:count;//记录最高位连续的1,例如1100XXXX,返回2
}

    /*
     如果当前数字最高位为-1，超过最大限制4，无效
     如果当前数字最高位位1：
            如果count<=0 无效
            否则count--
    如果最高位大于1：
            如果是count>0 无效，10还不够
            否则设置count=one-1
    最后判断当读到最后一个数组元素时，10是否已经足够
    */
    bool validUtf8(vector<int>& data) {
        int count=0;//记录10的个数
        int i;
        int one;
        for(i=0;i<data.size();i++){
            one = countOne(data[i]);
            if(one==-1)return false;
            if(one==1&&count-- <=0){
                return false;   
            }else if(one>1){
                if(count>0)return false;
                count=one-1;
            }
            if(i==data.size()-1&&count!=0)return false;
            
        }
        return true;
    
    
    }

int main(){
	int a;
	a=9;
	//cout<<findZero(128)<<endl;
	return 0;
} 
