#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
stack<int>st;
multiset<int>l,r;
void pop(int a){
    if(l.size()>r.size()){
        if(l.find(a)!=l.end()){
            l.erase(l.find(a));
        }else{
            r.erase(r.find(a));
            r.insert(*(--l.end()));
            l.erase((--l.end()));
        }
    }else if(l.size()==r.size()){
        if(r.find(a)!=r.end()){
            r.erase(r.find(a));
        }else{
            l.erase(l.find(a));
            l.insert(*(r.begin()));
            r.erase(r.begin());
        }
    }
}
void insert(int a){
    if(!l.size()){l.insert(a);return;}
    int mid=*(--l.end());
    if(l.size()>r.size()){
        if(a>=mid)r.insert(a);
        else if(a<mid){
            r.insert(mid);
            l.erase((--l.end()));
            l.insert(a);
        }
    }else if(l.size()==r.size()){
        if(a<=*r.begin())l.insert(a);
        else{
            l.insert(*r.begin());
            r.erase(r.begin());
            r.insert(a);
        }
    }
}
void solve(){
    string op;cin>>op;
    if(op=="Push"){
        int a;cin>>a;
        st.push(a);
        insert(a);
    }else if(op=="Pop"){
        if(!st.size()){
            cout<<"Invalid\n";
            return;
        }
        int a=st.top();
        cout<<a<<endl;
        st.pop();
        pop(a);
    }else{
        if(!st.size()){
            cout<<"Invalid\n";
            return;
        }
        cout<<*(--l.end())<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}