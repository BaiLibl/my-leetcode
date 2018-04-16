/*
使用优先队列
方法：
 struct cmp{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
   };
 priority_queue<元素，容器，方法cmp>
*/

class Solution {
private:
    struct cmp{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
   };
 
public:

vector< pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
	if(k<=0||nums1.size()==0||nums2.size()==0)return vector< pair<int,int> >();
	priority_queue< pair<int,int>,vector< pair<int,int> >,cmp> pq;
	int i,j;
	vector< pair<int,int> > res;
	for(i=0;i<nums1.size();i++){
		for(j=0;j<nums2.size();j++){
			pq.push(make_pair(nums1[i],nums2[j]));
			if(pq.size()>k)pq.pop();
		}
	}
	i=0;
	while(!pq.empty()){
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}
};
