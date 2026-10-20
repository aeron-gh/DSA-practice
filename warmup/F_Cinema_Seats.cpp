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
  int n, m, k;
  cin >> n >> m >> k;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j <= m - k; j++) {
      bool o = true;

      for (int x = j; x < j + k; x++) {
        if (s[x] == '#') {
          o = false;
          break;
        }
      }

      if (o)
        ans++;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  //   cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
