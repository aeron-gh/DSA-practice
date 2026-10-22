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
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
  }
  //   int a = 0;
  int ans = v[0] - 1;
  for (int i = 0; i < m - 1; i++) {
    if (v[i] <= v[i + 1]) {
      ans += v[i + 1] - v[i];
    } else {
      ans += n - v[i];
      ans += 1;
      ans += v[i + 1] - 1;
    }
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  //   cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
