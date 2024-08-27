#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        string a,b;cin>>a>>b;
        if(a[0]==b[0]){cout<<"YES"<<endl;cout<<a[0]<<'*'<<endl;}
        else if(a[a.size()-1]==b[b.size()-1]){
            cout<<"YES"<<endl;
            cout<<'*'<<a[a.size()-1]<<endl;
        }else{
            int flag=0;
            for(int i=1;i<a.size();i++){
                if(flag)break;
                for(int j=1;j<b.size();j++){
                    if(flag)break;
                    if(a[i]==b[j]&&a[i-1]==b[j-1]){
                        flag=1;
                        cout<<"YES"<<endl;
                        cout<<'*'<<a[i-1]<<a[i]<<'*'<<endl;
                    }
                }
            }
            if(!flag)cout<<"NO"<<endl;
        }
    }
    return 0;
}