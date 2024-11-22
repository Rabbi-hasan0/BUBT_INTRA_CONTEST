#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &i: a) {
            cin >> i;
        }
        vector<int> v;int ans = 0;  
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            if (it == v.end()) {
                v.push_back(a[i]);
                ans++;
            } else {
                *it = a[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
