#include<iostream>
#include<vector>
#include<set>
using namespace std;

//����AC 
//��Ŀ�и��������ֵķ��ز��ᳬ��31,��ô���ֻ����32λ��
//������һ���������ҵ�mask��������ȡ���ֵ�ǰ׺��Ȼ���䶼����set�У�
//������һ������t��������֤��ǰλΪ1�ٻ���֮ǰ���res��
//�������set�е�ǰ׺���֮���ڲ���set�У�
//�����õ���һ�����ʣ���a^b=c����ôa=b^c����Ϊt������Ҫ��֤�ĵ�ǰ���ֵ��
//�������Ǳ���set�е���ʱ����t����Ľ������set�У�
//˵������ǰ׺��������t��ֵ���������Ǹ���resΪt����������
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
