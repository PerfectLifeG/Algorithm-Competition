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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    int nx[n*20][2]={},idx=1;
    PII val[n*20]={};

    auto insert=[&](int x,int flag){
        int t=0;
        for(int i=19;i>=0;i--){
            int j=x>>i&1;
            if(!nx[t][j])nx[t][j]=idx++;
            t=nx[t][j];
            if(!flag)val[t].x++;
            else val[t].y++;
            // cout<<t<<' '<<val[t].x<<' '<<val[t].y<<endl;
        }
    };

    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){cin>>a[i];insert(a[i],0);}
    for(int i=0;i<n;i++){cin>>b[i];insert(b[i],1);}


    int cnt;
    auto query=[&](int x){
        int t=0;
        int res=0;
        for(int i=19;i>=0;i--){
            int p=0;
            if(nx[t][0])p=val[nx[t][0]].x*val[nx[t][0]].y;
            cout<<t<<' '<<x<<' '<<p<<' '<<val[nx[t][0]].x<<' '<<val[nx[t][0]].y<<endl;
            if(p<x){
                t=nx[t][1];
                res+=(1<<i);
                x-=p;
            }else{
                t=nx[t][0];
            }
        }
        return res;
    };

    int q;cin>>q;
    vector<PII>v;
    set<int>st{100000000000};
    unordered_map<int,int>mp;
    while(q--){
        int l,r;cin>>l>>r;
        v.push_back({l,r});
        if(!l){
            st.insert(r);
        }
    }
    for(auto i:st){
        mp[i]=query(i);
        cout<<i<<' '<<mp[i]<<endl;
    }

    for(int i=0;i<v.size();i++){
        if(v[i].x){
            auto l=st.lower_bound(v[i].x);
            while(*l!=100000000000){
                int t=mp[*l];
                mp[*l]=sqrt(t);
                if(t==1)st.erase(l);
                l++;
            }
        }else{
            cout<<mp[v[i].y]<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}