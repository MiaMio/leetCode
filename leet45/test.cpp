#include <iostream>
#include <vector>

using namespace std;

struct test
{
	int key;
	int val;
	test(int k, int v): key(k), val(v){}
};

int main(){
	
	vector<test*> v;
	v.push_back(new test(1, 2));
	v.push_back(new test(2, 3));
	cout<<(*v.begin())->key<<endl;
	
	// test* t=new test(1, 2);
	// cout<<t->key<<endl;

	// vector<int*> v;
	// v.push_back(new int(2));
	// cout<<**v.begin()<<endl;

}