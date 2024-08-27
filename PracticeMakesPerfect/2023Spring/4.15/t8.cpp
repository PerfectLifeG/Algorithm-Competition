#include<bits/stdc++.h>
using namespace std;
const int N=20010,mod=10007;
int bb[N];
int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        for(int j=b.size()-1;j>=0;j--){
            if(a[i]==b[j]){
                if(i>=j)bb[j]=(bb[j]+bb[j-1])%mod;
                if(j==0)bb[j]=(bb[j]+1)%mod;
            }
        }
    }
    cout<<bb[b.size()-1]%mod;
    return 0;
}