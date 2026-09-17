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
  int foo = pow(2, n);
  int bar = 0;

  for (int i = 0; i <= (foo / 2) - 1; i++) {
    bar += i;
    // cout << bar << " ";
  }

  int v = n;
  for (int i = n; i < n + (foo / 2); i++) {
    bar += v;
    v++;
    // cout << bar << " ";
  }
  cout << bar << " ";
  int a = gcd(foo, bar);
  cout << bar / a << '/' << foo / a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
