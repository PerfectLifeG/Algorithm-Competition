#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=400010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]>1){
        cout<<1<<endl;
        return;
    }
    vector<int>r(n+1);
    r[n-1]=n-1;
    int now=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]!=a[i+1]-1)now=i;
        r[i]=now;
    }
    int x=1,pos=0;
    for(int i=1;i<=k;i++){
        x+=r[pos]+1;
        while(r[pos]+1<n&&x>=a[r[pos]+1]){
            x+=r[r[pos]+1]-r[pos];
            pos=r[r[pos]+1];
        }
    }
    cout<<x<<endl;
    //1 
    //2 
    //3 
    //4 1    1   5   10   1 2 3 4 6 8 11 14 17 20+3 a[n]=
    //5 2                 5 7 9 12 15
    //6 3 1         8
    //7 4 2         11
    //8 5 3         14
    //9 6 4         17
    //10 7 5        20
    //11 8 6        23
    //12 9

    // 1       1 
    // 2 1 1 1 2 
    // 3 2 2 2 3 
    // 4 3 3 3 4 
    // 5 4 4 4 5 
    // 6 5 5 5 6 
    // 7 6 6 6 7 
    // 8 7 7 7 8 
    // 9 8 8 8 9 
    // 10
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}