#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
  int n, x;
  cin >> n >> x;
  int ans = 0;
  int a = 0;
  //   cin >> a;

  int foo = -5;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    if (i == n - 1) {
      foo = b;
    }
    ans = max(b - a, ans);
    a = b;
  }
  //   cin >> a;
  ans = max(2 * (x - foo), ans);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
