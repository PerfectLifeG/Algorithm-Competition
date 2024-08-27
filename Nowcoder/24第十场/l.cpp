#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m;
int tmp[10];
int trans(int a,int l,int r,int x){
    for(int i=n-1;i>=0;i--){
        tmp[i]=a%10;
        a/=10;
    }
    for(int i=l;i<=r;i++){
        tmp[i]=(tmp[i]+x)%10;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=res*10+tmp[i];
    }
    return res;
}

int add(int a,int b){
    for(int i=n-1;i>=0;i--){
        tmp[i]=a%10;
        a/=10;
    }
    for(int i=n-1;i>=0;i--){
        tmp[i]+=b%10;
        tmp[i]%=10;
        b/=10;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=res*10+tmp[i];
    }
    return res;
}

void solve(){
    cin>>n;
    int p10=pow(10,n);

    bool dp[p10][51]={};//从0转j次能否转到i
    dp[0][0]=1;

    queue<PII>q;
    q.push({0,0});
    while(q.size()){
        auto t=q.front();
        // cout<<t.x<<' '<<t.y<<endl;
        q.pop();
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                for(int i=1;t.y+i<=51;i++){
                    int x=trans(t.x,l,r,i);
                    if(!dp[x][t.y+i]){
                        dp[x][t.y+i]=1;
                        q.push({x,t.y+i});
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<":\n";
    //     for(int j=0;j<=50;j++){
    //         cout<<j<<' '<<dp[i][j]<<endl;
    //     }
    // }
    // return;

    int cnt[p10]={};
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        for(int j=0;j<p10;j++){
            int x=add(a,j);
            if(dp[j][b]){
                // cout<<a<<' '<<b<<' '<<x<<' '<<j<<endl;
                cnt[x]++;
            }
        }
    }

    int flag=-1;
    for(int i=0;i<p10;i++){
        if(cnt[i]==m){
            if(flag!=-1){
                cout<<"MANY\n";
                return;
            }
        }else flag=i;
    }
    if(flag==-1)cout<<"IMPOSSIBLE\n";
    else{
        string s=to_string(flag);
        for(int i=0;i<n-(int)s.size();i++)cout<<0;
        cout<<flag<<endl;
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}