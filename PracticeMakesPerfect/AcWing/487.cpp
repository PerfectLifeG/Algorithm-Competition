#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define x first
#define y second
typedef pair<int,int> PII;
int f[N];
PII a[N];
vector<PII>ve[N];
int main(){
    int n,m;cin>>m>>n;
    for(int i=1;i<n;i++){
        int v,t,p;
        cin>>v>>t>>p;
        if(!p)a[i]={v,v*t};//主件
        else ve[p].push_back({v,v*t});//附件
    }
    for(int i=1;i<n;i++){
        if(a[i].x){
            for(int j=0;j<n;j++){
                
            }
        }
        for(int j=m;j>=0;j--){
            for(int k=1;k<=ve[i].size()+1;k++){
                if(j>=a[i].x)f[j]=max(f[j],f[j-a[i].x]+a[i].y);
            }
        }
    }
    return 0;
}