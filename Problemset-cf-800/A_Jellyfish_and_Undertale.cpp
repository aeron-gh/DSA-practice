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
  int a, b, n;
  cin >> a >> b >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int no;
    cin >> no;
    if (no + b <= a) {
      b += no;
    } else {
      if (b - no <= 0) {
        ans += b;
        ans--;
      } else {
        ans += no;
      }
      int foo = min(a, no + 1);
      b = max(b, foo);
    }
  }

  ans += b;
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
