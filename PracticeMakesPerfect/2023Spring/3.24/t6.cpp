#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1001;
int C[N][N];
int a,b,n,p;
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}
int getnum(string &a){
    if(a.size()==0)return 1;
    int ret=0;
    for(int i=0;i<a.size();i++){
        ret=ret*10+(a[i]-'0');
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i)C[i][j]=1;
            else C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    string s;
    cin>>s;cout<<s<<" = ";
    int s1=0,s2=0,s3=0,s4=0;
    for(int i=0;i<s.size();i++){
        if(!s1){if(s[i]>='a'&&s[i]<='z')s1=i;}
        else if(s1&&!s2){if(s[i]>='a'&&s[i]<='z')s2=i;}
        if(s[i]=='^')s3=i;
        if(s[i]=='%')s4=i;
    }
    string aa=s.substr(1,s1-1);string bb=s.substr(s1+2,s2-s1-2);
    string cc;string dd=s.substr(s4+1,s.size()-s4-1);
    if(s3)cc=s.substr(s3+1,s4-s3-1);
    else cc="1";
    a=getnum(aa);b=getnum(bb);n=getnum(cc);p=getnum(dd);
    if(s3==0)n=1;
    if(s[s1]==s[s2]){
        int t=a+b;
        int x=ksm(t,n)%p;
        if(x==1){
            if(n>1)cout<<s[s1]<<"^"<<n<<"%"<<p;
            else cout<<s[s1]<<"%"<<p;
        }else if(x){
            if(n>1)cout<<x<<'*'<<s[s1]<<"^"<<n<<"%"<<p;
            else cout<<x<<'*'<<s[s1]<<"%"<<p;
        }else cout<<0;
        return 0;
    }
    int flag=1;vector<int>v;
    for(int i=0;i<=n;i++){
        int x=C[n][i]*ksm(a,n-i)*ksm(b,i)%p;
        if(x)flag=0;
        v.push_back(x);
    }
    if(flag){
        cout<<0;
        return 0;
    }
    cout<<'(';
    int fir=1;
    for(int i=0;i<v.size();i++){
        if(v[i]==0)continue;
        if(fir){
            if(v[i]==1&&n-i>1)cout<<s[s1]<<"^"<<n-i;
            else if(v[i]==1&&n-i==1)cout<<s[s1];
            else if(v[i]>1&&n-i==1)cout<<v[i]<<"*"<<s[s1];
            else if(v[i]>1&&n-i>1)cout<<v[i]<<"*"<<s[s1]<<"^"<<n-i;
            fir=0;
        }
        else {
            if(v[i]==1&&n-i>1)cout<<"+"<<s[s1]<<"^"<<n-i;
            else if(v[i]==1&&n-i==1)cout<<"+"<<s[s1];
            else if(v[i]>1&&n-i==1)cout<<'+'<<v[i]<<"*"<<s[s1];
            else if(v[i]>1&&n-i>1)cout<<'+'<<v[i]<<"*"<<s[s1]<<"^"<<n-i;
        }
        if(fir){
            if(v[i]>1&&i>1)cout<<v[i]<<"*"<<s[s2]<<"^"<<i;
            else if(v[i]==1&&i>1)cout<<s[s2]<<"^"<<i;
            else if(v[i]>1&&i==1)cout<<v[i]<<"*"<<s[s2];
            else if(v[i]==1&&i==1)cout<<s[s2];
        }else if(n-i==0){
            if(v[i]>1&&i>1)cout<<'+'<<v[i]<<"*"<<s[s2]<<"^"<<i;
            else if(v[i]==1&&i>1)cout<<"+"<<s[s2]<<"^"<<i;
            else if(v[i]>1&&i==1)cout<<'+'<<v[i]<<"*"<<s[s2];
            else if(v[i]==1&&i==1)cout<<"+"<<s[s2];
        }else{
            if(i>1)cout<<"*"<<s[s2]<<"^"<<i;
            else if(i==1)cout<<"*"<<s[s2];
        }
    }
    cout<<')';
    if(p!=1)cout<<'%'<<p;
    return 0;
}