#include<iostream>
#include<vector>
using namespace std;

//���λ�м���1 
int countOne(int num) {
    int count = 0;
    while((num&128)!=0){
        count++;
        num=(num<<1);
   }
 	return count>4?-1:count;//��¼���λ������1,����1100XXXX,����2
}

    /*
     �����ǰ�������λΪ-1�������������4����Ч
     �����ǰ�������λλ1��
            ���count<=0 ��Ч
            ����count--
    ������λ����1��
            �����count>0 ��Ч��10������
            ��������count=one-1
    ����жϵ��������һ������Ԫ��ʱ��10�Ƿ��Ѿ��㹻
    */
    bool validUtf8(vector<int>& data) {
        int count=0;//��¼10�ĸ���
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
