#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
unordered_map<char,int>mp;
int f[N];
int tr[6];
int lowbit(int x){
    return x&-x;
}
int n=5;
void add(int t, int x)
{
    for(int i = t; i <= n; i += lowbit(i))
        tr[i] += x;
}
int query(int t)
{
    int sum = 0;
    for(int i = t; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}
void solve(){
    string a;cin>>a;
    int ans=0;
    memset(tr,0,sizeof(tr));
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]=='A'){
            if(query(5)-query(1))ans-=mp[a[i]];
            else ans+=mp[a[i]];
            cout<<ans<<endl;
            add(1,1);
        }else if(a[i]=='B'){
            if(query(5)-query(2))ans-=mp[a[i]];
            else ans+=mp[a[i]];
            cout<<ans<<endl;
            add(2,1);
        }else if(a[i]=='C'){
            if(query(5)-query(3))ans-=mp[a[i]];
            else ans+=mp[a[i]];
            cout<<ans<<endl;
            add(3,1);
        }else if(a[i]=='D'){
            if(query(5)-query(4))ans-=mp[a[i]];
            else ans+=mp[a[i]];
            cout<<ans<<endl;
            add(4,1);
        }else if(a[i]=='E'){
            add(5,1);ans+=mp[a[i]];
            cout<<ans<<endl;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]=='A'){
            if(query(5)-query(1))t=max(t,ans+1+10000);
            else t=max(t,ans-1+10000);
            add(1,-1);
            break;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]=='B'){
            if(query(5)-query(1))t=max(t,ans+1+10000);
            else t=max(t,ans-1+10000);
            add(1,-1);
            break;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]=='C'){
            if(query(5)-query(1))t=max(t,ans+1+10000);
            else t=max(t,ans-1+10000);
            add(1,-1);
            break;
        }
    }
    for(int i=0;i<a.size();i++){
        if(a[i]=='D'){
            if(query(5)-query(1))t=max(t,ans+1+10000);
            else t=max(t,ans-1+10000);
            add(1,-1);
            break;
        }
    }
    int t=ans;
    for(int i=0;i<a.size();i++){
        if(a[i]=='A'){
            if(query(5)-query(1))t=max(t,ans+1+10000);
            else t=max(t,ans-1+10000);
            add(1,-1);
        }else if(a[i]=='B'){
            if(query(5)-query(2))t=max(t,ans+10+10000);
            else t=max(t,ans-10+10000);
            add(2,-1);
        }else if(a[i]=='C'){
            if(query(5)-query(3))t=max(t,ans+100+10000);
            else t=max(t,ans-100+10000);
            add(3,-1);
        }else if(a[i]=='D'){
            if(query(5)-query(4))t=max(t,ans+1000+10000);
            else t=max(t,ans-1000+10000);
            cout<<t<<endl;
            add(4,-1);
        }
    }
    cout<<t<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    mp['A']=1;mp['B']=10;mp['C']=100;mp['D']=1000;mp['E']=10000;
    while(T--){
        solve();
    }
    return 0;
}