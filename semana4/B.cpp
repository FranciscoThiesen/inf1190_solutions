#include <bits/stdc++.h>

using namespace std;

constexpr long long ninf = -1e12LL;
template <typename T> 
struct seg {
    int N;
    vector<T> tree;
    T identity;

    seg(int n, T id) : N(n), identity(id) { tree.assign(2 * N, id); }
    
    void build() {
        for(int idx = N - 1; idx > 0; --idx) {
            tree[idx] = tree[idx * 2] * tree[(idx * 2) | 1];
        }
    }

    void modify(int p, T val) {
        tree[p += N] = val;
        while(p > 1) {
            tree[p / 2] = tree[p] * tree[p ^ 1];
            p /= 2; 
        }
    }
    
    T query(int l, int r) {
        T res = identity;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) res = res * tree[l++];
            if(r & 1) res = res * tree[--r];
        }
        return res;
    }
};

struct node {
    long long max_rain;
    node(long long x = ninf) : max_rain(x) {}
    node operator* (const node& rhs) { return node(max(max_rain, rhs.max_rain)); }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        vector<long long> year, rain;
        auto S = seg<node>(n, node());
        
        for(int i = 0; i < n; ++i) {
            long long y_cur, r_cur;
            cin >> y_cur >> r_cur;
            year.push_back(y_cur);
            rain.push_back(r_cur);
            S.modify(i, node(r_cur)); 
        }

        // algumas coisas podem acontecer nas queries, vamos tratar todas em separado!

        
        
        
    }
    return 0;
}
