#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	struct Node
	{
		int value;
		int distance;
		int times;
		Node(int v, int d, int t) : value(v), distance(d), times(t) {}
	};
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1)	return 0;
		
		int size = nums.size();
		int* visit=new int[size];
		for (int i = 0; i < size; i++) {
			visit[i] = 0;
		}
		
		vector<Node*> v;
		v.push_back(new Node(nums[0], size - 1, 0));
		vector<Node*>::iterator v_begin=v.begin();
		vector<Node*>::iterator v_now;
		v_now=v_begin;

		visit[0] = 1;
		int now=0;
		while (!v.empty()) {
			Node* now_node=v[0];
			int now_time=now_node->times;
//			cout<<"now: "<<now<<" now_time: "<<now_time<<endl;
			if(size-1-now<=nums[now]){
				return now_time+1;
			}
			
			for(int i=1; i<=nums[now]; i++){
				if(visit[now+i]==0){
//					cout<<"if now: "<<now<<" i: "<<i<<" now_time: "<<now_time<<endl;
					v.push_back(new Node(nums[now+i], size-1-now-i, now_time+1));
					visit[now+i]=1;
				}
			}
			v.erase(v.begin());
			now++;
		}
	}
};

int main()
{
	vector<int> nums = {6,2,6,1,7,9,3,5,3,7,2,8,9,4,7,7,2,2,8,4,6,6,1,3};
	Solution* sol = new Solution();
	cout << "result: " << sol->jump(nums) << endl;
    return 0;
}