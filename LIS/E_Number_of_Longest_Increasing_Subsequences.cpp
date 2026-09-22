#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
  int n;
  cin >> n;
  int arr[n];

  for (auto &a : arr) {
    cin >> a;
  }
  int dp[n];
  int cnt[n];
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    cnt[i] = 1;
  }
  // memset(cnt, 1, sizeof(cnt));
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          cnt[i] = cnt[j];
          cnt[i] = cnt[i];
        } else if (dp[i] == dp[j] + 1) {
          cnt[i] = (cnt[i] + cnt[j]) % MOD;
        }
      }
    }
    mx = max(mx, dp[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == mx) {
      ans = (ans + cnt[i]) % MOD;
    }
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
