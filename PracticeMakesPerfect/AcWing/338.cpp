#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int get(vector<int> &num,int l,int r){
    int s=0;
    for(int i=l;i>=r;i--){
        s=s*10+num[i];
    }
    return s;
}
int count(int n,int x){
    vector<int>num;
    while (n)
    {
        num.push_back(n%10);
        n/=10;
    }
    n=num.size();
    int res=0;
    for(int i=n-1-!x;i>=0;i--){
        if(i<n-1){
            res+=get(num,n-1,i+1)*pow(10,i);
            res-=pow(10,i)*(!x);
        }
        if(num[i]==x)res+=get(num,i-1,0)+1;
        if(num[i]>x)res+=pow(10,i);
    }
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b,a||b){
        if(a>b)swap(a,b);
        for(int i=0;i<10;i++){
            cout<<count(b,i)-count(a-1,i)<<' ';
        }
        puts("");
    }
    return 0;
}