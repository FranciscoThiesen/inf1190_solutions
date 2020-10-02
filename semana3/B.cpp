#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})
#define rep(i, a, b) for(int i = (a); (i) < (b); ++(i))
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>(x.size())
#define mp make_pair
#define fi first
#define se second

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void buff() { ios::sync_with_stdio(false); cin.tie(nullptr); }

constexpr ll MOD = 1e9 + 7;

inline ll pow_mod(ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod; assert(b >= 0);
    for(;b;b>>=1) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

template<typename T> inline void remin(T& x, const T& y) { x = min(x, y); }
template<typename T> inline void remax(T& x, const T& y) { x = max(x, y); }

template<typename T> ostream& operator<<(ostream &os, const vector<T>& v) {
    os << "{"; string sep; for(const auto& x : v) os << sep << x, sep = ", "; return os << "}"; 
}

template<typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
    os << "{"; string sep; for(const auto& x : arr) os << sep << x, sep = ", "; return os << "}"; 
}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { 
    return os << '(' << p.first << ", " << p.second << ')'; 
}

int main() {
    buff();
    int n;
    cin >> n;
    char cur_end = '9';
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        if(x[0] == cur_end) {
            ans++;
        }
        cur_end = x[1];
    }
    cout << ans << endl;
    return 0;
}

