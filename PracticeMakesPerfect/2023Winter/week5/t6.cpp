#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int s[N];
int p;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string a;cin>>a;
        if(a=="Pop"){
            if(p==0)cout<<"Invalid"<<endl;
            else cout<<s[p--]<<endl;
        }else if(a=="PeekMedian"){
            if(p==0)cout<<"Invalid"<<endl;
            else if(p&1) cout<<s[(p+1)/2]<<endl;
            else cout<<s[p/2]<<endl;
        }else{
            int x;cin>>x;
            s[++p]=x;
        }
    }
    return 0;
}