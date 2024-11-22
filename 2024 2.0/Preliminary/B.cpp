#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4e5, mod = 1e9 + 7;
int factorial[N];

int power(long long n, long long k, int mod) { 
  int ans = 1 % mod; 
  n %= mod; 
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

void factorial_precal() {
    factorial[1] = factorial[0] = 1;
    for(int i = 2; i <= N; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= mod;
    }
}

int ncr(int n, int r) {
    int x = power(factorial[r], mod - 2, mod) * power(factorial[n - r], mod - 2, mod) % mod;
    return (factorial[n] * x) % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    factorial_precal();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ans = ncr(n + 1, k + 1);
        cout << ans << '\n';
    }
    return 0;
}
