#include<iostream>
#include<vector>
using namespace std;
//���������
//��������ʱ���¼ 
#include <stdlib.h> 
#include <time.h> 

/*
//ϣ�����򣺲�������ĸ�Чʵ��
�Ƚ�������¼�ָ�����������зֱ�������򣬴��������л�������ʱ������һ����ȫ�������� 
*/ 
void shell_partition(vector<int>& num,int d){
	int n=num.size();
	int i,j;
	for(i=d;i<n;i++){
		j=i-d;
		int tmp=num[i];
		while(j>=0&&num[j]>tmp){
			num[j+d]=num[j];
			j=j-d;
		}
		if(j!=i-d)num[j+d]=tmp;//�ҵ����ʵ�λ�ò��� 
								//���Ǿ�j<0�����ģ���Ӧ�ò鵽j+d�� 
	}
} 
void shell_sort(vector<int>& num){
	int n=num.size();
	int d=n/2;//�����С
	while(d){
		shell_partition(num,d);
		d=d/2;
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
	shell_sort(a);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

	//����������ʱ���㷨ִ��Ч����Ч����� 
	start_time=clock();
	shell_sort(b);
	end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;	
    
	//���������ʱ���㷨ִ��Ч����Ч��һ�� 
	start_time=clock();
	shell_sort(c);
	end_time=clock();
	cout<< "ordered data Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	
	cout<<istrue(a)<<endl;
	cout<<istrue(b)<<endl;
	cout<<istrue(c)<<endl;
	return 0;
}
