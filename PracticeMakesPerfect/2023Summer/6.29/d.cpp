#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int b[N];
void solve(){
    int idx=0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;){
        // cout<<i<<' '<<idx<<endl;
        if(a[i]==0){i++;continue;}
        int j=i+1;
        int s=a[i];
        while(j<n&&(a[j]<=0&&a[i]<0||a[j]>=0&&a[i]>0)){
            s+=a[j];
            j++;
        }
        b[idx++]=s;
        i=j;
        // cout<<i<<' '<<idx-1<<' '<<b[idx-1]<<endl;
    }
    // cout<<endl;
    int idx1=0;
    // cout<<idx<<endl;
    // for(int i=0;i<idx;i++){
    //     cout<<b[i]<<' ';
    // }
    // cout<<endl;
    for(int i=0;i<idx;i++){
        // cout<<b[i]<<' ';
        if(b[i]<0&&i+1<idx&&b[i]+b[i+1]<=0){
            if(i+2<idx){a[idx1++]=b[i]+b[i+1]+b[i+2];i++;}
            else{
                a[idx1++]=b[i]+b[i+1];
            }
            i++;
        }
        else a[idx1++]=b[i];
    }
    // cout<<endl;
    int ans=0;
    int t=0;
    int s=0;
    for(int i=0;i<idx1;i++){
        // cout<<a[i]<<' ';
        if(a[i]<0){
            if(t>a[i]){
                t=a[i];
                ans=s;
            }
        }
        s+=a[i];
    }
    // cout<<endl;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}