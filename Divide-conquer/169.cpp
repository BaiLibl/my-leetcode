#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*摩尔投票(Boyer–Moore majority vote algorithm)，时间复杂度O(n)，空间复杂度O(1)
摩尔投票的思想是用一个计数器进行计数，当一个元素的计数为0时，替换该元素

步骤一：维护一个候选数candidate和计数器counter。遍历数组中所有的元素， 设当前的元素为x，若 counter = 0,则 candidate = x, counter = 1; 否则， 根据candidate 与x是否相等来更新counter（相等+1，不等-1）
步骤二：再遍历一次，判断候选数是否为合法的主元素。

*/

//一对一对的删除，最后剩余的那一个就是所求的元素 

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
