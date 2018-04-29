#include<iostream>
#include<vector>
using namespace std;
//随机数生成
//程序运行时间记录 
#include <stdlib.h> 
#include <time.h> 
/*
插入排序： 
假设前面i-1都是已经排好的，将num[i]和前面的数组比较，找到一个合适的位置
*/

void Insert_sort(vector<int>& num){
	int n=num.size();
	int i,j;
	for(i=1;i<n;i++){
		int target=num[i];//暂存要求排序的对象 
		j=i;
		while(j>0&&target<num[j-1]){ //j>0
			num[j]=num[j-1];
			j--;
		}
		//找到合适插入的地方 
		num[j]=target;
	}
} 

//检测排序算法的正确性 
bool istrue(vector<int>& a){
	int i;
	i=1;
	while(i<a.size()&&a[i]>=a[i-1])i++;
	if(i==a.size())return true;
	return false;
}

int main(){
	vector<int> a;
	vector<int> b;
	vector<int> c;
	int i,j;
	clock_t start_time;
	clock_t end_time;
	
	for(i=0;i<10000;i++)a.push_back(i);
	for(i=10000;i>=0;i--)b.push_back(i);
	srand((unsigned)time(NULL)); 
	for(i=0;i<10000;i++){
		  c.push_back(rand()%10000);
	}
	
	//当数据有序时，算法执行效果: 效果最好 
	start_time=clock();
	Insert_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//当数据逆序时，算法执行效果：效果最差 
	start_time=clock();
	Insert_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//当数据随机时，算法执行效果：效果一般 
	start_time=clock();
	Insert_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
