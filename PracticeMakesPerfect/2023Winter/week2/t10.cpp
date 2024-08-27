#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
vector<int>v;
int main(){
    int n,m;cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        s.insert(a);
    }
    cnt=*s.begin();
    v.push_back(*s.begin());
    s.erase(s.begin());
    for(int i=m;s.size();i++){
        if(i<n){int a;cin>>a;s.insert(a);}
        auto it=s.lower_bound(cnt);
        if(it!=s.end()){
            v.push_back(*it);
            s.erase(it);
            cnt=*it;
        }else{
            int flag=1;
            for(auto it:v){
                if(flag){cout<<it;flag=0;}
                else cout<<' '<<it;
            }
            puts("");
            v.clear();
            cnt=*s.begin();
            v.push_back(cnt);
            s.erase(s.begin());
        }
    }
    int flag=1;
    for(auto it:v){
        if(flag){cout<<it;flag=0;}
        else cout<<' '<<it;
    }
    return 0;
}