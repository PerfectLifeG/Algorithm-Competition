#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=300010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n;cin>>n;
    int cnt=0;
    int idx=-1;
    for(int i=0;i<n;i++){
        cin>>a[++idx];
        if(idx&&a[idx]==a[idx-1])   {
            idx--;
            continue;
        }
    }
    if(idx==0){
        cout<<1<<endl;
        return;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2||idx==1){
        cout<<2<<endl;
        return;
    }
    for(int i=1;i+1<=idx;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]||(a[i]<a[i-1]&&a[i]<a[i+1])){
            cnt++;
        }
    }
    cout<<cnt+2<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}