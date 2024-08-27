#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

#include <bits/stdc++.h>
#define min(a,b) (a > b ? b : a)
#define max(a,b) (a < b ? b : a)

#define YES (print("Y); cout <<" << ); cout <<e; print(
#define NO (print("); cout <<" << ); cout <<e; print(
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define mem(a,b) memset(a,b,sizeof(a))
#define rrep(a, b, c) for (a = b; a >= c; a--)
#define rep(a, b, c) for (a = b; a <= c; a++)
#define lowbit(a) (a & (-a))
#define int long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);

using namespace std;

typedef double db;
typedef pair<__int128,__int128> pii;
typedef array <int,3> a3;

const db eps = 1e-7;
const __int128 inf = 1e26;
const int N = 200010;

void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

void solve(){
    int x,y;
    cin >> x >> y;

    int g = __gcd(x,y);
    __int128 a = x / g;
    __int128 b = y / g;
    pii res = {inf, inf};
    
    if (b == 1){
        pii ans = {x, y}; 
        auto [l,r] = ans;
        print(r); printf(" ");
        print(l / r); printf("\n");
    }else if (b % 2 == 0){
        pii ans = {b * x, y};
        auto [l,r] = ans;
        print(r); printf(" ");
        print(l / r); printf("\n");
    }else{
        pii ans = {x * b * 2, y * 2};
        auto [l,r] = ans;
        print(r); printf(" ");
        print(l / r); printf("\n");
    }
}

/*


*/

signed main(){

    int T = 1;
    cin >> T;

    while (T --){
        solve();
    }

    system("pause");
}