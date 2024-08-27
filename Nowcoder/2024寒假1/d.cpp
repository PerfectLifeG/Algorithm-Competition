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
unordered_map<int,int>mp;
unordered_map<int,int>cnt;
void solve(){
    int n,q;cin>>n>>q;
    set<int>st{0};
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    cnt=mp;
    if(n==1){
        while(q--){
            int a;cin>>a;
            yes;
        }
        return;
    }else if(n>=30){
        for(auto [x,y]:cnt){
            if(n-mp[x]-mp[x-2]>=30)continue;
            int flag=1;
            int sum=1;
            for(int i=0;i<n;i++){
                sum*=(v[i]-(x-1));
                if(sum>1e9||sum<-1e9){flag=0;break;}
            }
            if(flag)st.insert(sum);
            if(n-mp[x]-mp[x+2]>=30)continue;
            flag=1;sum=1;
            for(int i=0;i<n;i++){
                sum*=(v[i]-(x+1));
                if(sum>1e9||sum<-1e9){flag=0;break;}
            }
            if(flag)st.insert(sum);
        }
    }else{
        sort(all(v));
        for(int i=n-1;i>=0;i--)v[i]-=v[0];
        for(int j=-1e5;j<=1e5;j++){
            for(int i=0;i<n;i++){
                int flag=1;
                int sum=1;
                for(int i=0;i<n;i++){
                    sum*=(v[i]-j);
                    if(sum>1e9||sum<-1e9){flag=0;break;}
                }
                if(flag)st.insert(sum);
            }
        }
        reverse(all(v));
        for(int i=n-1;i>=0;i--)v[i]-=v[0];
        for(int j=-1e5;j<=1e5;j++){
            for(int i=0;i<n;i++){
                int flag=1;
                int sum=1;
                for(int i=0;i<n;i++){
                    sum*=(v[i]-j);
                    if(sum>1e9||sum<-1e9){flag=0;break;}
                }
                if(flag)st.insert(sum);
            }
        }
    }
    while(q--){
        int a;cin>>a;
        if(st.count(a))yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}