#include<bits/stdc++.h>
using namespace std;
inline int read() {
	char c = getchar();
	if(c=='0')
	return 0;
    else return 1;
}
int main()
{
    int t;cin>>t;
    for (int j = 0; j < t; j++)
    {
        int c[100005];
        char cc;
        c[0]=-1;
        int p;cin>>p;getchar();
        int i=1;
        while((cc=getchar())!='\n')
        {
            if(cc=='1'){
                if(c[i-1]==1)i--;
                else {c[i]=1;i++;}
            }
            if(cc=='0'){
                if(c[i-1]==0)i--;
                else {c[i]=0;i++;}
            }
        }
        i--;
        if(i==0){
            cout<<0<<endl;
            continue;
        }
        int c1=0;int ii=i;
        while (i>0)
        {
            if(c[i]==1)c1++;
            i--;
        }
        int c0=ii-c1;
        if(c1==c0)cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}