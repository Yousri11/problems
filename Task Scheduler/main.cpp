#include <bits/stdc++.h>

using namespace std;

vector<pair<string,pair<int,int>>> ssort(unordered_map<string,pair<int,int>> m){
    vector<pair<int,pair<string,int>>> v;
    vector<pair<string,pair<int,int>>> v2;
    unordered_map<string,pair<int,int>> res;
    for(auto i:m){
        //m2[i.second.first]={i.second.second,i.first};
        v.push_back(make_pair(i.second.first,make_pair(i.first,i.second.second)));
        //cout<<i.second.first<<"  "<<m2[i.second.first].second<<"   "<<i.first<<endl;
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        //cout<<v[i].second.first<<"  "<<v[i].second.second<<"   "<<v[i].first<<endl;
        int a=v[i].first,c=v[i].second.second;
        string b=v[i].second.first;
        v2.push_back(make_pair(b,make_pair(a,c)));
    }
    return v2;
}
    int dfs(vector<pair<string,pair<int,int>>>& v,int n,int pos ,int l,int c){
        if(c==l)return 0;
        //cout<<" possssssssss = "<<pos<<endl;
        bool ok=false;
        int res=10000;
            for(auto i:v){
                if(i.second.first != 0){
                    if(pos >= i.second.second + n + 1 || i.second.second== -1 ){
                    //cout<<i.first <<"  "<<i.second.first<<"  "<<i.second.second<<endl;
                        int s = i.second.second;
                        //cout<<" s = "<<s<<endl;
                        i.second.second=pos;
                        i.second.first--;
                        int t=dfs(v,n,pos+1,l,c+1);
                        //cout<<i.first <<"  "<<m[i.first].first<<"  "<<m[i.first].second<<endl;
                        res=min(res,t);
                        //m[i.first].second=s;
                        //m[i.first].first++;
                        ok=true;
                    }
                }
            }


        if(!ok){
            //cout<<" pos = "<<pos<<" c "<<c<<endl;
            int t=1+dfs(v,n,pos+1,l,c);
            res=min(res,t);
            }
        return res;
    }
 int solve(vector<string>& tasks, int n) {
        int l=tasks.size();
        unordered_map<string,pair<int,int>> m;
        for(auto i:tasks){
            m[i].first++;
            m[i].second=-1;
        }
       // cout<<"==================================================================="<<endl;
        vector<pair<string,pair<int,int>>> v;
        v=ssort(m);
        int res=1000;
        for(auto i:v){
                //cout<<"alo : " <<i.first <<"  "<<i.second.first<<"  "<<i.second.second<<endl;
            i.second.second=0;
            i.second.first--;
            res=min(res,dfs(v,n,1,l,1));
            break;
            //m[i.first].second=-1;
            //m[i.first].first++;
        }
        return res+l;
}

int main()
{
    int n;
    //int x=6;
    vector<string> v{"A","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    //vector<string> v{"B","A","A","B","B","B", "C","C","C", "D", "D", "E"};
    /*for(int i=0;i<x;i++){
        char c;
        cin>>c;
        v.push_back(c);
    }*/

    cin>>n;

    int h=solve(v,n);
    cout<<"res = "<<h;
    return 0;
}
