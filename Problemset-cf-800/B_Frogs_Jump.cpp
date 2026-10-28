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
  int n;
  cin >> n;

  int f = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'f') {
        f++;
      }
    }
  }
  if (f % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
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
