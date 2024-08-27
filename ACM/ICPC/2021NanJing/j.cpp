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
void solve(){
    int a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    int t=b-a;
    vector<int>v;
    for(int i=2;i<=t/i;i++){
        while(t%i==0){
            v.push_back(i);
            t/=i;
        }
    }
    if(t>1){
        v.push_back(t);
    }
    // for(auto i:v)cout<<i<<' ';cout<<endl;

    int cha=1e18;
    int p=0;
    vector<int>tmp;
    vector<int>num;
    function<void(int,int)> dfs=[&](int t,int now){
        // cout<<t<<' '<<now<<' '<<a<<endl;
        // for(auto i:tmp)cout<<i<<' ';cout<<endl;
        if(now>=a){
            if(now-a<cha){
                cha=now-a;
                num=tmp;
                p=now;
            }
            return;
        }
        if(t>=v.size()){
            // cout<<now<<' '<<a<<'.'<<cha<<endl;
            if(abs(now-a)<cha){
                cha=abs(now-a);
                num=tmp;
                p=now;
            }
            return;
        }

        tmp.push_back(v[t]);
        if(now==0) dfs(t+1,v[t]);
        else dfs(t+1,now*v[t]);
        tmp.pop_back();
        dfs(t+1,now);
    };

    dfs(0,0);
    if(p==0){
        cout<<a-1<<endl;
        return;
    }
    // for(auto i:num)cout<<i<<' ';cout<<endl;
    // cout<<a<<endl;
    // return;
    int ans=0;
    vector<int>book((int)num.size());
    if(p<a){
        for(int j=0;j<num.size();j++){
            int mn=1e9;
            int q=-1;
            for(int i=0;i<num.size();i++){
                if(book[i])continue;
                if(a%num[i]<mn){
                    mn=a%num[i];
                    q=i;
                }
            }
            book[q]=1;
            ans+=a%num[q];
            ans++;
            a-=a%num[q];
            a/=num[q];
        }
        cout<<ans+a-1<<endl;
    }else{
        cout<<num.size()+p-a<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}