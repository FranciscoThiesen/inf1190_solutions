#include <bits/stdc++.h>

using namespace std;

int calc_1(const string& s) {
    char cur = s[0];
    int tam = static_cast<int>( s.size() );
    int ans = 0;
    char leave = 'U';
    for(int i = 1; i < tam; ++i) {
        if(s[i] != cur) {
            ans++;
            cur = s[i];
        }
        if(cur != leave) ans++;
        cur = leave;
    }
    return ans;
}

int calc_2(const string& s) {
    char cur = s[0];
    int tam = static_cast<int>( s.size() );
    int ans = 0;
    char leave = 'D';
    for(int i = 1; i < tam; ++i) {
        if(s[i] != cur) {
            ans++;
            cur = s[i];
        }
        if(cur != leave) ans++;
        cur = leave; 
    }
    return ans;
}

int calc_3(const string& s) {
    char cur = s[0];
    int tam = static_cast<int>(s.size());
    int ans = 0;
    for(int i = 1; i < tam; ++i) {
        if(s[i] != cur) {
            ans++;
            cur = s[i];
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << calc_1(s) << endl << calc_2(s) << endl << calc_3(s) << endl;
    return 0;
}
