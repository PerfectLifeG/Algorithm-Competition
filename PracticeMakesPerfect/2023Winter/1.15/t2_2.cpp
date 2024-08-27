#include<bits/stdc++.h>
using namespace std;
#define sc(n) scanf("%d",&n)
int main(){
    int t;sc(t);
    while(t--){
        int n;sc(n);vector<int>v;
        int cnt=0;int ans=0;
        for(int i=0;i<n;i++){
            int a;sc(a);v.push_back(a);
        }
        sort(v.begin(),v.end());
        int i=0;while(v[i]==0){i++;cnt++;}
        for(;i<v.size();i++){
            if(v[i]>cnt){
                int t=cnt;
                cnt+=v[i]-cnt;            
                i+=v[i]-t;
                if(i+1<v.size()&&v[i]<=cnt)ans++;
                else while(v[i+1]==v[i]&&v[i]>cnt){
                    i++;cnt++;
                }
                if(i+1<v.size()&&v[i]<=cnt)ans++;
            }
            cnt++;
        }
        printf("%d\n",ans+2);
    }
    return 0;
}