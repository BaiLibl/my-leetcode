#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

static bool compare(const Interval& a,const Interval& b){
	return a.start<=b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> res;
	if(intervals.size()==0)return res;
	sort(intervals.begin(),intervals.end(),compare);
	int i;
	res.push_back(intervals[0]);
	for(i=1;i<intervals.size();i++){
		if(res[res.size()-1].end<intervals[i].start){
			res.push_back(intervals[i]);
		}else{
			res[res.size()-1].end=max(res[res.size()-1].end,intervals[i].end);
		}
	}
    return res;
}

int main(){
	return 0;
} 
