#include<bits/stdc++.h>
using namespace std;
#define sc(n) scanf("%d",&n)
unordered_map<int,int>mp;
int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n);vector<int>v;
        int cnt=0;int ans=0;
        for(int i=0;i<n;i++){
            int a;sc(a);v.push_back(a);
            mp[a]++;
        }
        sort(v.begin(),v.end());
        int i=0;while(v[i]==0){i++;cnt++;}
        for(;i<v.size();i++){
            if(v[i+1]!=v[i]){
                if(v[i]>cnt)ans++;
                else {
                    int j=i;
                    for(;j<v.size();j++){
                        if(v[j]==cnt)break;
                        cnt++;
                    }
                    i=j;
                }
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}