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
  if (n == 1) {
    cout << "Deficient" << endl;
    return;
  }
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n) {
        ans += i;
      } else {
        ans += i;
        if (i != 1) {
          ans += n / i;
        }
      }
    }
  }

  if (ans == n) {
    cout << "Perfect" << endl;
  } else if (ans > n) {
    cout << "Abundant" << endl;
  } else {
    cout << "Deficient" << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1000;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
