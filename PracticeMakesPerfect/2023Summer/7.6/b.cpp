#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int n;
int f;
int check(int x){
    int t=a[0];
    int cnt=0;
    for(int i=0;i<n;i++){
        if(t==f){cnt++;if(i+1<n)t=a[i+1];continue;}
        t=t&a[i];
        // if(t==f){cnt++;}
    }
    cout<<cnt<<endl;
    if(cnt>=x)return 1;
    else return 0;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    f=a[0];
    for(int i=1;i<n;i++){
        f=f&a[i];
    }
    if(f!=0){
        cout<<1<<endl;
        return;
    }
    int cnt=0;
    for(int i=0;i<n;){
        int t=a[i];
        int j=i+1;
        if(t==0){
            cnt++;
            i++;
            continue;
        }
        int p=0;
        while(j<n){
            t=t&a[j];
            j++;
            if(t==0){p=1;break;}
        }
        // cout<<i<<' '<<t<<endl;
        if(p)cnt++;
        i=j;
    }
    cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}