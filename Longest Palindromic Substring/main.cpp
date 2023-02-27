#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    string res;
    for(int i=1;i<s.size();i++){
        int l=i-1,r=i+1;
        while(l>=0 &&r<s.size()&&s[l]==s[r] ){
            l--;
            r++;
        }

        string ch=s.substr(l+1,r-(l+1));
        if(ch.size()>res.size())res=ch;
        if(s[i]==s[i-1]){
            l=i-2;
            r=i+1;
            while(s[l]==s[r] && l>=0 &&r<s.size()){
            l--;
            r++;
            }
            string ch=s.substr(l+1,r-(l+1));
            if(ch.size()>res.size())res=ch;
        }
    }
    cout<<res;
    return 0;
}
