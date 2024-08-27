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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    int g[3][3]={};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)g[i][j]=-1;
    }
    int flag=0;
    for(int p=0;p<n;p++){
        int x,y,z;cin>>x>>y>>z;
        // cout<<flag<<endl;
        if(flag)continue;
        x--,y--;
        if(x==y&&z!=0)flag=1;
        if(g[x][y]==-1){
            if(z==0)g[x][y]=2;
            if(z==1){g[x][y]=1;g[y][x]=0;}
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        if(i!=x||j!=y||k==x||k==y)continue;
                        if(z==1){
                            if(g[j][k]==1){
                                if(g[i][k]!=-1&&g[i][k]!=1)flag=1;
                                g[i][k]=1;
                                g[k][i]=0;
                            }
                        }else{
                            if(g[j][k]==2){
                                if(g[i][k]!=-1&&g[i][k]==1)flag=1;
                                g[i][k]=2;
                            }
                            if(g[j][k]==0){
                                if(g[i][k]!=-1&&g[i][k]==1)flag=1;
                                // g[i][k]=0;
                                // g[k][i]=1;
                            }
                            if(g[j][k]==1){
                                if(g[k][i]==2){g[k][i]=0;g[i][k]=1;}
                            }
                        }
                    }
                }
            }
            for(int i=0;i<3;i++){
                if(flag)break;
                for(int j=i+1;j<3;j++){
                    if((g[i][j]==1||g[i][j]==0)&&g[i][j]==g[j][i]){flag=1;break;}
                }
            }
        }
        else{
            if(z==1){
                if(g[x][y]!=-1&&g[x][y]!=1)flag=1;
                if(g[y][x]!=-1&&g[y][x]==1)flag=1;
                if(z==0)g[x][y]=2;
                if(z==1){g[x][y]=1;g[y][x]=0;}
            }else{
                if(g[x][y]!=-1&&g[x][y]==1)flag=1;
                if(g[y][x]!=-1&&g[y][x]==0)flag=1;
                if(z==0)g[x][y]=2;
                if(z==1){g[x][y]=1;g[y][x]=0;}
            }
            for(int i=0;i<3;i++){
                if(flag)break;
                for(int j=i+1;j<3;j++){
                    if((g[i][j]==1||g[i][j]==0)&&g[i][j]==g[j][i]){flag=1;break;}
                }
            }
        }
    }
    if(flag)no;
    else yes;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}