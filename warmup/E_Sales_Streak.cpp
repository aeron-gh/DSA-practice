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

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 1, m = 1, s = 1, an = 1;

  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) {
      l++;
    } else {
      l = 1;
      s = i + 1;
    }

    if (l > m) {
      m = l;
      an = s;
    }
  }
  cout << m << " " << an << endl;
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
