#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee*> employees, int id) {
	 int res=0;
	 int imp =0;
	 map<int,vector<int> > mp1;
	 int i,j;
	 vector<int> tmp;
	 for(i=0;i<employees.size();i++){
	 	Employee* em=employees[i];
	 	if(em->id == id){
	 		imp=em->importance;
			tmp=em->subordinates;
			break;	
	 	}
	 }       
	 for(j=0;j<tmp.size();j++){
	 	res+=getImportance(employees,tmp[j]);
	 }
	 
	 return res+imp;
}

int main(){
	return 0;
}

