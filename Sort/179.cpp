
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

  static bool compare(const string& a,const string& b){
	return (a+b)>(b+a);
}

string largestNumber(vector<int>& nums) {
	string res="";
	if(nums.size()==0)return res;
	vector<string> s;
	int i;
	for(i=0;i<nums.size();i++){
		stringstream ss;
		string tmp;
		ss<<nums[i];
		ss>>tmp;
		s.push_back(tmp);	
	}
	sort(s.begin(),s.end(),compare);
	for(i=0;i<s.size();i++)res+=s[i];
    if(res[0]=='0'){
        return "0";
    }
	return res;
	
}

int main(){
	vector<string> s;
	s.push_back("3");
	s.push_back("30");
	s.push_back("34");
	s.push_back("5");
	s.push_back("9");
	vector<int> a;
	a.push_back(3);
	a.push_back(30);
	a.push_back(34);
	a.push_back(5);
	a.push_back(9);
	//sort(s.begin(),s.end(),compare);
	//reverse(s.begin(),s.end());
	int i;
	//for(i=0;i<s.size();i++)cout<<s[i]<<' ';
	cout<<largestNumber(a);

//	cout<<compare("34","3000")<<endl;
	
}
