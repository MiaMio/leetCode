#include <iostream>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
        int s_ptr=0;
        int p_ptr=0;
        int star_ptr=-1;
        int record_s=0;

        while(s[s_ptr]){
            if(p[p_ptr]==s[s_ptr] || p[p_ptr]=='?'){
                cout<<"comin if1"<<endl;
                p_ptr++;
                s_ptr++;
                continue;
            }
            if(p[p_ptr]=='*'){
                cout<<"comin if2"<<endl;
                star_ptr=p_ptr++;
                record_s=s_ptr;
                continue;
            }
            if(star_ptr>=0){
                cout<<"comin if3"<<endl;
                p_ptr=star_ptr+1;
                s_ptr=record_s++;
                continue;
            }
            return false;
        }
        while(p[p_ptr]=='*')
            p_ptr++;
        if(p_ptr<p.length())    return false;
        else    return true;
    }
};

int main(){
    string s, p;
    Solution* sol=new Solution();
    while(1){
        cin>>s>>p;
        cout<<s<<" "<<p<<endl;
        cout<<sol->isMatch(s, p)<<endl;
    }
}