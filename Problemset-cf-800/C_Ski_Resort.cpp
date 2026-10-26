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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i] <= q) {
      cnt++;
    } else {
      if (cnt >= k) {
        int a = (cnt + 1) - k;
        ans += (a * (a + 1)) / 2;
      }
      cnt = 0;
    }
  }
  if (cnt >= k) {
    int a = (cnt + 1) - k;
    ans += (a * (a + 1)) / 2;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
