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
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    a.erase(unique(a.begin(),a.end()),a.end());

    int x=40;
    int i=0;
    vector<int>ans;
    while(x--){
        if(i==a.size()-1){
            if(a[0]!=0)ans.push_back(a[i]);
            for(int j=0;j<a.size();j++)a[j]=abs(a[j]-a[i]);
            break;
        }
        int t;
        if((a[i]+a[i+1])%2==0){
            t=(a[i]+a[i+1])/2;
            ans.push_back(t);
            i++;
        }else{
            cout<<-1<<endl;
            return;
        }
        for(int j=0;j<a.size();j++)a[j]=abs(a[j]-t);
    }
    if(a[0]==0){
        if(ans.size()>40){
            cout<<-1<<endl;
            return;
        }
        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i<<' ';cout<<endl;
    }else cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}