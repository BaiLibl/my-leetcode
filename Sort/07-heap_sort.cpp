#include<iostream>
#include<vector>
using namespace std;
//随机数生成
//程序运行时间记录 
#include <stdlib.h> 
#include <time.h> 

/*
堆排序：初始建堆
		插入数据，修改堆以满足堆的性质 
- 利用完全二叉树，堆顶和末尾互换，保持堆的性质不变 
- 最大堆：根结点的值是所有结点中值最大的，且每个结点的值都大于儿子结点的值
- 最小堆：根结点的值是所有结点中值最小的，且每个结点的值都小于儿子结点的值 
*/ 
void adjustHeap(vector<int>& arrs, int p, int len){ //修改以p为根的子树，len是数组的长度 
    int curParent = arrs[p];
    int child = 2* p + 1;   //左孩子
    while(child < len){     //没有孩子
        if(child+1<len&&arrs[child]<arrs[child+1]){
            child++;    //较大孩子的下标
        }
        if(curParent<arrs[child]){
            arrs[p]=arrs[child];
            //没有将curParent赋值给孩子是因为还要迭代子树，
            //如果其孩子中有大的，会上移，curParent还要继续下移。
            p=child; //父结点小于子结点，子结点上移，父结点下移 
            child=2*p+1; //更新子结点 
        }
        else  
            break;
    }
    arrs[p]=curParent;
}
void heap_sort(vector<int>& num){
	int n=num.size();
	int i;
	//建堆 
	for(i=n/2-1;i>=0;i--){ //i起始值为n/2-1，就是取地板 
		adjustHeap(num,i,n);
	}
	//排序 
	for(i=n-1;i>=0;i--){
		swap(num[0],num[i]);
		adjustHeap(num,0,i);
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
bool isfalse(vector<int>& a){
	int i;
	i=1;
	while(i<a.size()&&a[i]<=a[i-1])i++;
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
	heap_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//当数据逆序时，算法执行效果：效果最差 
	start_time=clock();
	heap_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//当数据随机时，算法执行效果：效果一般 
	start_time=clock();
	heap_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
