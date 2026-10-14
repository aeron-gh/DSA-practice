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
  int a, b, c;
  cin >> a >> b >> c;
  if ((a > b and a < c) or (a < b and a > c)) {
    cout << a << endl;
  } else if ((b > a and b < c) or (b > c and b < a)) {
    cout << b << endl;
  } else {
    cout << c << endl;
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
