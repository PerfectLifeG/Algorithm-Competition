#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
    int t;cin>>t;
    for (int j = 0; j < t; j++)
    {
        int n;cin>>n;
        int a,k,b,m;
        int tree[1010];
        for (int i = 0; i < n; i++)
        {
            cin>>tree[i];
        }
        cin>>a>>k>>b;
        cin>>m;
        m--;
        for (int i = 0; i < n; i++)
        {
            if(tree[i]+m*a<=k)printf("%d ",tree[i]+m*a);
            else {
                int mm=m-(k-tree[i])/a-1;
                tree[i]=b;
                while(mm-(k-tree[i])/a-1>0)mm-=(k-tree[i])/a;
                printf("%d ",tree[i]+mm*a);
            }
        }
        puts("");
    }
    return 0;
}