#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int l=0;
        int r=s.size()-1;
        int ans=0;
        while(l<=r){
            // cout<<l<<' '<<r<<endl;
            int flag=0;
            while(l<=r&&s[l]=='B'){
                l++;
                flag=1;
            }
            if(flag){
                int t=0;
                while(l<=r&&s[l]=='A'){
                    t++;
                    l++;
                }
                ans+=t;
                flag=0;
            }

            while(l<=r&&s[r]=='B'){
                r--;
                flag=1;
            }
            // cout<<l<<' '<<r<<' '<<flag<<endl;
            if(flag){
                int t=0;
                while(l<=r&&s[r]=='A'){
                    t++;
                    r--;
                }
                ans+=t;
                flag=0;
            }

            int ll=l;int t1=0;
            while(ll<=r&&s[ll]=='A')ll++;
            if(ll<=r&&s[ll]=='B')t1=ll-l;

            int t2=0;int rr=r;
            while(l<=rr&&s[rr]=='A')rr--;
            if(l<=rr&&s[rr]=='B')t2=r-rr;
            // cout<<t1<<'.'<<t2<<endl;

            if(t1>t2){
                l=ll+1;
                ans+=t1;
            }else{
                ans+=t2;
                r=rr-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}