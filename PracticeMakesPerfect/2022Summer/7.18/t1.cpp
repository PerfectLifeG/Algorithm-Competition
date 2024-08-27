#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int n;cin>>n;getchar();
    for (int i = 0; i < n; i++)
    {
        int cnt=1;int flag=0;
        c=getchar();
        if(!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||c=='_'||c=='$'))
        {flag=1;}
        while(c!='\n'&&(c=getchar())!='\n'){
            if(!((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z')||c=='_'||c=='$')){
                flag=1;
            }
            cnt++;
        }
        if(cnt>32||flag)
            cout<<"CE"<<endl;
        else cout<<"OK"<<endl;
    }
    return 0;
}