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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    vector<int>b(n);
    
    vector<array<int,3>>v;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        v.push_back({a[i],b[i],i});
    }
    sort(all(v));


    vector<int>tmp;
    for(int i=n-1;i>=0;i--){
        if(v[i][1]==0){
            tmp.push_back(v[i][2]);
            break;
        }
    }

    int t=n/2;if(n%2==0)t--;
    // int p=t-1;
    // while(p>=0&&b[p]==1)p--;
    // if(p>=0)tmp.push_back(p);p--;
    // while(p>=0&&b[p]==1)p--;
    // if(p<0)p=0;
    // tmp.push_back(p);
    // p=t+1;
    // while(p<n&&b[p]==1)p++;
    // if(p<n)tmp.push_back(p);p++;
    // while(p<n&&b[p]==1)p++;
    // if(p>=n)p=n-1;
    // tmp.push_back(p);
    // if(b[t]==0)tmp.push_back(t);




    int x=(n-1)/2+1;
    auto check=[&](int mid,int idx){
        int cnt=0;
        int f=n;
        for(int i=0;i<n;i++){
            if(v[i][2]==idx)continue;
            if(v[i][0]>=mid){
                cnt++;
                if(f==n){
                    f=i;
                }
            }
        }
        if(cnt>=x)return 1;
        int p=x-cnt;
        // cout<<p<<' '<<f<<endl;
        int t2=0;
        for(int i=f-1;i>=0&&p;i--){
            if(v[i][2]==idx)continue;
            if(v[i][1]==1){
                t2+=mid-v[i][0];
                if(t2>k)return 0;
                p--;
            }
        }
        // cout<<mid<<' '<<idx<<' '<<p<<endl;
        if(p)return 0;
        return 1;
    };


    int ans=0;
    for(auto i:tmp){
        int l=0,r=2e9+1;
        while(l+1!=r){
            int mid=l+r>>1;
            // cout<<i<<' '<<l<<' '<<r<<endl;
            if(check(mid,i))l=mid;
            else r=mid;
        }
        // cout<<i<<' '<<l<<endl;
        ans=max(ans,a[i]+l);
    }

    map<int,int>mp;
    for(int i=0;i<n;i++){
        if(!mp.count(v[i][0]))mp[v[i][0]]=i;
    }

    for(int i=0;i<n;i++){
        if(b[i]){
            int idx=mp[a[i]];
            int x;
            if(n%2==0){
                if(idx>t)x=v[t][0];
                else x=v[t+1][0];
            }else{
                if(idx>=t)x=v[t-1][0];
                else x=v[t][0];
            }
            // cout<<a[i]<<' '<<k<<' '<<x<<endl;
            ans=max(ans,a[i]+k+x);
        }
    }
    cout<<ans<<endl;


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}