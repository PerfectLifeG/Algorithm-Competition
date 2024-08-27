#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void mul(int a[][2], int b[][2], int c[][2])
{
    int temp[][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
            for (int k = 0; k < 2; k ++ )
            {
                long long x = temp[i][j] + (long long)a[i][k] * b[k][j];
                temp[i][j] = x % MOD;
            }
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
            c[i][j] = temp[i][j];
}
int f_final(long long n)
{
    if (!n) return 1;

    int x[2] = {1, 1};
    int res[][2] = {{1, 0}, {0, 1}};
    int t[][2] = {{1, 1}, {1, 0}};
    long long k = n - 1;
    while (k)
    {
        if (k&1) mul(res, t, res);
        mul(t, t, t);
        k >>= 1;
    }

    int c[2] = {0, 0};
    for (int i = 0; i < 2; i ++ )
        for (int j = 0; j < 2; j ++ )
        {
            long long r = c[i] + (long long)x[j] * res[j][i];
            c[i] = r % MOD;
        }

    return c[0];
}
void solve(){
    long long n;cin>>n;
    if(n==0ll)cout<<0<<endl;
    else if(n==1ll)cout<<1<<endl;
    else cout<<f_final(n+2ll)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}