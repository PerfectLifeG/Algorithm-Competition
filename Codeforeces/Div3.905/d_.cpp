#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int T;cin>>T;
    int now=0;
    int c=0;
    // vector<PII>v;
    multiset<PII>v;
    // v.push_back({1e9+1});
    while(T--){
        string op;
        int a,b;cin>>op>>a>>b;
        if(op[0]=='+'){
            v.insert({a,b});
            // sort(v.begin(),v.end());
        for(auto i:v)cout<<i.x<<'.'<<i.y<<endl;
            // int l=c-1,r=v.end();
            // auto t=lower_bound(v.begin()+c,v.end(),make_pair(a,b))-v.begin();
            auto t1=distance(v.lower_bound(make_pair(b+1,b+1)),v.begin());
            auto t2=distance(prev(v.upper_bound(make_pair(a-1,a-1))),v.begin());
            cout<<t2<<' '<<t1<<endl;
            now+=(t2);
            now+=((int)v.size()-t1);
        }
        else{
            v.erase({a,b});
            for(auto i:v)cout<<i.x<<'.'<<i.y<<endl;
            // int l=c-1,r=v.end();
            // auto t=lower_bound(v.begin()+c,v.end(),make_pair(a,b))-v.begin();
            auto t1=distance(lower_bound(v.begin(),v.end(),make_pair(b+1,b+1)),v.begin());
            auto t2=distance(prev(upper_bound(v.begin(),v.end(),make_pair(a-1,a-1))),v.begin());
            // cout<<t2<<' '<<t1<<endl;
            now-=(t2);
            now-=((int)v.size()-t1);
            // sort(v.begin(),v.end());
            // int l=c-1,r=v.end();
        //     auto t1=lower_bound(v.begin(),v.end(),make_pair(b+1,b+1))-v.begin();
        //     auto t2=prev(upper_bound(v.begin(),v.end(),make_pair(a-1,a-1)))-v.begin();
        //     // cout<<t2<<' '<<t1<<endl;
        //     auto t=lower_bound(v.begin(),v.end(),make_pair(a,b))-v.begin();
        //     // v[t].x=0;
        //     // v[t].y=0;
        // // for(auto i:v)cout<<i.x<<'.'<<i.y<<endl;
        //     // cout<<t<<endl;
        //     now-=(t2-c+1);
        //     now-=((int)v.size()-t1);
        //     c++;
        }
        // cout<<now<<endl;
        if(now){
            yes;
        }else no;   
    }

}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}