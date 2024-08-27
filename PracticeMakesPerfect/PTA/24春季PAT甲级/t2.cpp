#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<string,int>mp;
int p[100010][10];
signed main(){
    int mid[6]={};
    int n,m;cin>>n>>m;
    vector<int>v[6];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]=i;
        for(int j=1;j<=5;j++){
            int a;cin>>a;
            p[i][j]=a;
            v[j].push_back(a);
        }
    }
    for(int i=1;i<=5;i++){
        sort(v[i].begin(),v[i].end());
    reverse(v[i].begin(),v[i].end());
        mid[i]=v[i][(n-1)/2];
    }
    
    while(m--){
        string s;cin>>s;
        if(!mp.count(s)){
            cout<<"Not Found\n";
            continue;
        }
        vector<int>v1,v2;
        for(int i=1;i<=5;i++){
            if(p[mp[s]][i]>=mid[i]){
                v1.push_back(i);
            }else v2.push_back(i);
        }
        sort(v1.begin(),v1.end(),[&](int a,int b){
            if(p[mp[s]][a]-mid[a]!=p[mp[s]][b]-mid[b])
            	return p[mp[s]][a]-mid[a]>p[mp[s]][b]-mid[b];
            return a<b;
        });
        sort(v2.begin(),v2.end(),[&](int a,int b){
            if(mid[a]-p[mp[s]][a]!=mid[b]-p[mp[s]][b])
                return mid[a]-p[mp[s]][a]<mid[b]-p[mp[s]][b];
            return a<b;
        });
        int first=1;
        for(int i=0;i<v1.size();i++){
            if(first){
                cout<<v1[i];first=0;
            }else cout<<' '<<v1[i];
        }
        for(int i=0;i<v2.size();i++){
            if(first){
                cout<<'-'<<v2[i];first=0;
            }else cout<<' '<<'-'<<v2[i];
        }cout<<endl;
    }
}
