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
  int n, l, d;
  cin >> n >> l >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i] = a;
  }
  sort(v.begin(), v.end());

  int rounds = d / l;
  int ans = rounds * n;

  int foo = d % l;
  //   cout << foo;
  if (rounds % 2 == 0) {
    int a = 0;
    int z = n - 1;
    int idx = -1;
    while (a <= z) {
      int mid = a + (z - a) / 2;
      if (v[mid] <= foo) {
        idx = mid;
        a = mid + 1;
      } else {
        z = mid - 1;
      }
    }
    ans += idx + 1;
  } else {
    int x = l - foo;
    int a = 0;
    int z = n - 1;
    int idx = -1;
    while (a <= z) {
      int mid = (a + z) / 2;
      if (v[mid] >= x) {
        idx = mid;
        z = mid - 1;
      } else {
        a = mid + 1;
      }
    }
    if (idx != -1) {
      ans += n - idx;
    }
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
