#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*Ħ��ͶƱ(Boyer�CMoore majority vote algorithm)��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
Ħ��ͶƱ��˼������һ�����������м�������һ��Ԫ�صļ���Ϊ0ʱ���滻��Ԫ��

����һ��ά��һ����ѡ��candidate�ͼ�����counter���������������е�Ԫ�أ� �赱ǰ��Ԫ��Ϊx���� counter = 0,�� candidate = x, counter = 1; ���� ����candidate ��x�Ƿ����������counter�����+1������-1��
��������ٱ���һ�Σ��жϺ�ѡ���Ƿ�Ϊ�Ϸ�����Ԫ�ء�

*/

//һ��һ�Ե�ɾ�������ʣ�����һ�����������Ԫ�� 

int majorityElement(vector<int>& num) {
	int curIdx = 0, count = 1;
    for (int i = 1; i < num.size(); ++i)
    {
        num[i] == num[curIdx] ? ++count : --count;
        if (!count)
        {
            curIdx = i;
            count = 1;
        }
     }

    return num[curIdx];
}

int main(){
	vector<int> p;
	int i;
	for(i=0;i<5;i++)
		p.push_back(i);
	cout<<majorityElement(p)<<endl;
	return 0;
} 
