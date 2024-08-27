#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define lowbit(x) (x&(-x))
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e6;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void add(int tr[],int t,int val){
    for(int i=t;i<=N;i+=lowbit(i)){
        tr[i]+=val;
    }
}
int query(int tr[],int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr[i];
    }
    return res;
}
int tr[N+1];
int tr2[N+1];
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=query(tr,a[i]-1);
        add(tr,a[i],1);
    }
    int ans=0;
    if(sum>=k)ans=1;
    for(int i=0,j=0;i<n;i++){
        j=max(j,i);
        while(j<n&&sum>=k){
            add(tr,a[j],-1);
            sum-=query(tr,a[j]-1);
            sum-=query(tr2,N)-query(tr2,a[j]);
            if(sum<k){
                sum+=query(tr,a[j]-1);
                sum+=query(tr2,N)-query(tr2,a[j]);
                add(tr,a[j],1);
                break;
            }
            j++;
        }
        ans+=j-i;
        if(j>i){
            sum+=query(tr,a[i]-1);
            sum+=query(tr2,N)-query(tr2,a[i]);
        }
        add(tr2,a[i],1);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}