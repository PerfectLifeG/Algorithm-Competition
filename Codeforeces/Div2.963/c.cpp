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
    vector<PII>a(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        a[i]={v[i],i};
        // a[i].second=i;
    }
    sort(all(a));
    int x=a[0].first;
    for(int i=0;i<n;i++)a[i].first-=x;
    // for(int i=0;i<n;i++)cout<<a[i].first<<' ';cout<<endl;
    
    // 8 0 2

    
    


    // 0 1 2 3 4      10 11 12 13 14

    // 2 3 4 5 6      12 13 14 15 16

    // 8 9 10 11 12  



    // 0~k-1  ok
    // 2k~3k-1 
    // 0 1 2 3 4           10 11 12 13 14

    // 4 5 6 7 8           14 15 16 17 18
    
    // 8 9 10 11 12        18 19 20 21 22

        //-1 0
    //0 1 2 3 4           10 11 12 13 14
    //9 10 11 12 13       19 20 21 22 23

    for(int i=0;i<n;i++){
        int t=a[i].first/k;
        if(t&1)t--;
        a[i].first-=t*k;
        if(a[i].first>=k){
            a[i].first-=2*k;
        }
        // if(a[i]==0)a[i]+=2*k;
        // cout<<a[i].first<<' ';
    }
    // cout<<endl;
    int mx=-INF,mn=INF;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i].first);
        mn=min(mn,a[i].first);
    }
    if(mx-mn>=k){cout<<-1<<endl;return;}

    // -1 0 1 2

    // 0 1 2 3  8 9 10 11
    // 1 2 3 4  9 10 11 12
    // 2 3 4 5  10 11 12 13
    // 7 8 9 10



    int t=0;
    sort(all(a));
        // cout<<a[i].first<<' ';
    if(a[0].first<0){
        t=a[0].first+2*k+mx-mn;
    }else t=a[n-1].first;
    for(int i=0;i<n;i++){
        if(a[i].first<0)a[i].first+=2*k;
    }

    // cout<<endl;
    // cout<<t<<endl;

    for(int i=0;i<n;i++){
        // cout<<t<<' '<<a[i].first<<' '<<v[a[i].second]<<endl;
        a[i].first=t-a[i].first+v[a[i].second];
        // cout<<a[i].first<<' '<<endl;
        // ans=max(ans,);
    }
    // return;
    int ans=0;
    for(int i=0;i<n;i++){
        int t=(a[i].first-v[a[i].second])/k;
        if(t&1)t--;
        v[a[i].second]=a[i].first-t*k;
        ans=max(ans,v[a[i].second]);
        // cout<<t<<' '<<a[i].first<<' '<<v[a[i].second]<<endl;
        // a[i].first=t-a[i].first+v[a[i].second];
        // ans=max(ans,);
    }
    // cout<<endl;
    cout<<ans<<endl;




}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}