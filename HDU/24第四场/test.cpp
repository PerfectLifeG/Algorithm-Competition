#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

#include <bits/stdc++.h>
#define min(a,b) (a > b ? b : a)
#define max(a,b) (a < b ? b : a)

#define YES (cout << "YES" << endl)
#define NO (cout << "NO" << endl)
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
typedef pair<int,int> pii;
typedef array <int,3> a3;

const db eps = 1e-7;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 200010;
const int MOD = 1e9;

int a[N], b[N], c[N];
bool op[N];
// int n,q;

void solve(){
    int n=2e5,q=2e5;
    mt19937 rand(time(0));

    int i;
    int sum = 0;
    int cnt = 0;

    rep(i,0,n - 1){
        op[i] = 0;
        a[i]=rand()%MOD+1;
        sum += a[i];
    }

    rep(i,0,n - 1){
        b[i]=rand()%MOD+1;
        c[i] = b[i];
    }

    sort (c, c + n);
    int mx = c[n - 1];

    map <int,int> mp;

    auto find = [&](int x) -> int {
        if (mp.count(x)) return mp[x];
        int pos = upper_bound(c, c + n, x) - c;
        if (x == n) return 0;
        return pos;
    };

    rep(i,0,n- 1) find(a[i]);
    rep(i,0,n- 1) find(b[i]);

    set <int> pop;

    rep(i,0,n - 1){
        cnt += find(a[i]);
        if (a[i] < mx){
            pop.insert(i);
        }
    }

    while (q --){
        int x = max((cnt / n + 1), 1);
        int k=rand()%n;

        vector <int> pop2;

        if (x >= pop.size()) x = pop.size();

        while (x --){
            for (int p : pop){
                if (a[p] < b[(p + k) % n]){
                    sum -= a[p];
                    cnt -= find(a[p]);

                    a[p] = b[(p + k) % n];
                    
                    sum += a[p];
                    cnt += find(a[p]);
                }

                if (a[p] >= mx){
                    pop2.push_back(p);
                }
            }
        }

        for (int x : pop2){
            pop.erase(x);
        }
       
        cout << sum << endl;
    }
}   

signed main(){
    cin.tie(0);
    IOS;
    freopen("out.txt","w",stdout);

    int T = 1;
    cin >> T;

    while (T --){
        solve();
    }

    // system("pause");
}