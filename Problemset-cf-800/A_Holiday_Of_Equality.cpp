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
  int a = -1;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (a < vec[i]) {
      a = vec[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i] < a) {
      ans += (a - vec[i]);
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
