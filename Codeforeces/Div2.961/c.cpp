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
    vector<int>c(n);

    int ans=0;
    for(int i=1;i<n;i++){
        if(a[i]==1&&a[i-1]>1){
            cout<<-1<<endl;
            return;
        }
        int k=0;int cur=a[i-1];
        while(cur!=1&&cur*cur<=a[i]){
            cur=cur*cur;
            k++;
        }
        int x1=1e9;
        if(cur<=a[i])x1=max(0ll,c[i-1]-k);

        cur=a[i];k=0;
        while(a[i-1]>cur){
            cur=cur*cur;
            k++;
        }
        int x2=c[i-1]+k;
        
        c[i]=min(x1,x2);
        ans+=c[i];
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