#include<bits/stdc++.h>
using namespace std;
int post[30],dfs[30];
int n,cnt;
void create(int index){
    if(index>n) return;
    create(index*2);
    create(index*2+1);
    dfs[index]=post[cnt++];
}
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    create(1);
    cout<<dfs[1];
    for (int i = 2; i <= n; i++)
    {
        cout<<" "<<dfs[i];
    }
    return 0;
}