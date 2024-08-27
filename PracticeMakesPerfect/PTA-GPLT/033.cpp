#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    stack<int>s1;
    stack<char>s2;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        s1.push(a);
    }
    for (int i = 0; i < n-1; i++)
    {
        char c;cin>>c;
        s2.push(c);
    }
    while(!s1.empty()){
        int a,b;char c;
        a=s1.top();s1.pop();
        b=s1.top();s1.pop();
        c=s2.top();s2.pop();
        if(c=='+')a=b+a;
        if(c=='-')a=b-a;
        if(c=='*')a=b*a;
        if(c=='/'){
            if(a==0){
                printf("ERROR: %d/%d\n",b,a);
                return 0;
            }
            a=b/a;
        }
        if(s1.empty()){cout<<a;break;}
        s1.push(a);
    }
    return 0;
}