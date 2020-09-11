#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int first_one = 100000, last_one = -1;
        int tam = static_cast<int>( s.size() );
        for(int i = 0; i < tam; ++i) {
            if(s[i] == '1') {
                first_one = min(first_one, i);
                last_one = max(last_one, i);
            }
        }
        if(last_one == -1) cout << 0 << endl;
        else {
            int ans = 0; 
            for(int i = first_one; i <= last_one; ++i) {
                if(s[i] == '0') ++ans;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
