#include<bits/stdc++.h>
using namespace std;
int num[10005];
int book[10005];
int flag;
int isprime(int n){
    if(n==1)return 0;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int isperfect(int n){
    set<int>s;
    int sum=0;
    int a=n;
    while(a!=1){
        s.insert(a);
        sum=0;
        while(a){
            int t=a%10;
            sum+=t*t;
            a/=10;
        }
        num[n]++;
        book[sum]=1;
        a=sum;
        if(s.count(sum)==1) return 0;
    }return 1;
}
int main()
{
    int a,b;cin>>a>>b;
    vector<int>v;
    for (int i = a; i <= b; i++)
    {
        if(isperfect(i))v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(isprime(v[i])&&book[v[i]]==0){cout<<v[i]<<" "<<2*num[v[i]]<<endl;flag=1;}
        else if(book[v[i]]==0){cout<<v[i]<<" "<<num[v[i]]<<endl;flag=1;}
    }
    if(flag==0){
        cout<<"SAD";
    }
    return 0;
}