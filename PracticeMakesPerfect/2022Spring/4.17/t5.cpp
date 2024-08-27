#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int s=0;int ss=0;
    for (int i = 0; i < n; i++)
    {
        long long a;cin>>a;
        int j = 1;
        for (; j < 10; j++)
        {
            int b=a*j;
            ss=0;
            while(b)
            {
                ss+=b%10;
                b/=10;
            }
            if(s==0)s=ss;
            else if(ss!=s)break;
        }
        if(s==ss&&j==10)cout<<s<<endl;
        else cout<<"NO"<<endl;
        s=0;
    }
    return 0;
}