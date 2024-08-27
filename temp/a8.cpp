#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define i64 long long
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(i64 n) {
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n)
            return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}
std::vector<i64> factorize(i64 n) {
    std::vector<i64> p;
    std::function<void(i64)> f = [&](i64 n) {
        if (n <= 10000) {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i)
                    p.push_back(i);
            if (n > 1)
                p.push_back(n);
            return;
        }
        if (isprime(n)) {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) {
            return (mul(x, x, n) + 1) % n;
        };
        i64 x0 = 2;
        while (true) {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1) {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0) {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam) {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n) {
                f(d);
                f(n / d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    std::sort(p.begin(), p.end());
    return p;
}

vector<int>divs;
unordered_map<int,int>mp;
vector<PII>vv;
void dfs(int t,int x){
    if(t==vv.size()){
        if(x<10)return;
        divs.push_back(x);
        return;
    }
    for(int i=0;i<=vv[t].second;i++){
        dfs(t+1, x);
        x *= vv[t].first;
    }
}

int check(int m){
    int cnt=0;
    while(m){
        cnt+=m%10;
        m/=10;
    }
    return cnt;
}

void solve(){
    int ans=0;
    int n;
    n=1e12-1;
    for(int sm=1;sm<110&&sm<=n;sm++){
        vv.clear();
        divs.clear();
        mp.clear();
        int x=n-sm;
        vector<int> v=factorize(x);


        for(auto j:v)mp[j]++;
        for(auto [i,j]:mp)vv.push_back({i,j});

        dfs(0,1);

        // cout<<x<<":"<<endl;
        // for(auto m:divs){
        //     cout<<m<<endl;
        // }
        // continue;

        for(auto m:divs){
            if(check(m)==sm&&m<=n){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("out.txt","w",stdout);
    int _=100;
    while(_--)solve();
    return 0;
}