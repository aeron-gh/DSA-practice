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
  int n, k;
  cin >> n >> k;
  if (1 + ((k - 1) * 2) <= n) {
    cout << 1 + ((k - 1) * 2);
  } else {
    if (n % 2 == 0) {
      k -= n / 2;
    } else {
      k -= (n / 2 + 1);
    }
    cout << 2 + ((k - 1) * 2);
  }
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
