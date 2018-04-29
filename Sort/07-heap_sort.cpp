#include<iostream>
#include<vector>
using namespace std;
//���������
//��������ʱ���¼ 
#include <stdlib.h> 
#include <time.h> 

/*
�����򣺳�ʼ����
		�������ݣ��޸Ķ�������ѵ����� 
- ������ȫ���������Ѷ���ĩβ���������ֶѵ����ʲ��� 
- ���ѣ�������ֵ�����н����ֵ���ģ���ÿ������ֵ�����ڶ��ӽ���ֵ
- ��С�ѣ�������ֵ�����н����ֵ��С�ģ���ÿ������ֵ��С�ڶ��ӽ���ֵ 
*/ 
void adjustHeap(vector<int>& arrs, int p, int len){ //�޸���pΪ����������len������ĳ��� 
    int curParent = arrs[p];
    int child = 2* p + 1;   //����
    while(child < len){     //û�к���
        if(child+1<len&&arrs[child]<arrs[child+1]){
            child++;    //�ϴ��ӵ��±�
        }
        if(curParent<arrs[child]){
            arrs[p]=arrs[child];
            //û�н�curParent��ֵ����������Ϊ��Ҫ����������
            //����亢�����д�ģ������ƣ�curParent��Ҫ�������ơ�
            p=child; //�����С���ӽ�㣬�ӽ�����ƣ���������� 
            child=2*p+1; //�����ӽ�� 
        }
        else  
            break;
    }
    arrs[p]=curParent;
}
void heap_sort(vector<int>& num){
	int n=num.size();
	int i;
	//���� 
	for(i=n/2-1;i>=0;i--){ //i��ʼֵΪn/2-1������ȡ�ذ� 
		adjustHeap(num,i,n);
	}
	//���� 
	for(i=n-1;i>=0;i--){
		swap(num[0],num[i]);
		adjustHeap(num,0,i);
	}
}

//��������㷨����ȷ�� 
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
	
	//����������ʱ���㷨ִ��Ч��: Ч����� 
	start_time=clock();
	heap_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//����������ʱ���㷨ִ��Ч����Ч����� 
	start_time=clock();
	heap_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//���������ʱ���㷨ִ��Ч����Ч��һ�� 
	start_time=clock();
	heap_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
