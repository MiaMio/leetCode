#include <iostream>

using namespace std;

class Solution {
private:
	
public:
	int help(long long target){
		long long sum=0;
		long long remain=target/5;
		if(remain==0)
			return 0;
		sum+=remain;
		return help(remain)+sum;
	}
    int preimageSizeFZF(int K) {
    	if(K==0)	return 5;
    	long long head=K;
    	long long tail=5*head;
    	cout<<head<<" "<<tail<<endl;
    	while(head<=tail){
    		cout<<"head: "<<head<<"tail: "<<tail<<endl;
    		long long mid=(head+tail)/2;
    		if(help(mid)==K)	return 5;
    		else if(help(mid)>K)	tail=mid-1;
    		else	head=mid+1;
    	}
    	return 0;
    }
};

int main(){
	Solution* sol=new Solution();
	int num;
	while(1){
		cin>>num;
		cout<<sol->preimageSizeFZF(num)<<endl;	
	}
	
}