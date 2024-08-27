#include<bits/stdc++.h>
using namespace std;
#define sc(n) scanf("%d",&n)
const int N=100010;
int n,m;
int main(){
    int t;sc(t);
    while(t--){
        scanf("%d",&n);
        vector<vector<int>>v(n+1);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                int a;scanf("%d",&a);
                v[i].push_back(a);
                mp[v[i][j]]++;
            }
        }
        int st=0;
        for(int i=0;i<n;i++){
            int flag=1;
            for(int j=0;j<v[i].size();j++){
                if(mp[v[i][j]]==1){
                    flag=0;
                    break;
                }
            }
            if(flag){st=1;break;}
        }
        if(st)puts("YES");
        else puts("NO");
    }
    return 0;
}