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
  int n, m, a;
  cin >> n >> m >> a;
  int foo = 0;
  int bar = 0;
  if (n % a == 0) {
    foo = n / a;
  } else {
    foo = (n / a) + 1;
  }
  if (m % a == 0) {
    bar = m / a;
  } else {
    bar = (m / a) + 1;
  }
  cout << foo * bar;
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
