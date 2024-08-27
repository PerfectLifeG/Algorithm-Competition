#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;){
        int j=i+1;
        if(!a[i]||a[i]==3){i++;continue;}
        int f=0;
        if(a[i]==2)f=1;
        while(j<n&&a[j]){
            if(a[j]==2)f=1;
            j++;
        }
        if(f){
            if(i>0&&!a[i-1])a[i-1]=3;
            a[j]=3;j++;
        }else{
            if(i>0&&!a[i-1])a[i-1]=3;
            else a[j]=3,j++;
        }
        ans++;
        i=j;
    }
    for(int i=0;i<n;i++)if(!a[i])ans++;
        cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}