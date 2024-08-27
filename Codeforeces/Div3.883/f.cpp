#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int now=n;
    int f,t;

    function<int(int)> fun=[&](int n){
        unordered_map<int,int>mp2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp2[a[i]]++;
        }
        f=0,t=0;
        for(auto i:mp2){
            if(mp[i.first]>i.second)f=i.first;
            else if(mp[i.first]<i.second)t=i.first;
        }
        if(f==0&&t==0){
            return 0;
        }else if(mp2[t]==1){
            for(int i=0;i<n;i++){
                if(a[i]==t){
                    cout<<"! "<<i+1<<endl;
                    return 1;
                }
            }
        }else{
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(a[i]!=t)
                ans.push_back(i);
            }
            cout<<"- "<<ans.size();
            for(auto i:ans)cout<<' '<<i+1;
            cout<<endl;
            now=n-ans.size();
            mp.clear();
            mp[t]=mp2[t];
            if(fun(now))return 1;
            return 0;
        }

    };

    while(1){
        cout<<"- 0"<<endl;
        if(fun(now))return;
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}