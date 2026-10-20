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
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;
  int a = h2 - h1; // 4
  if (m2 > m1) {
    a++; // 5
  }
  a -= 2;
  if (a >= 0) {
    if (a * 20 > 100) {
      cout << 100;
    } else {
      cout << a * 20;
    }
  } else {
    cout << 0;
  }
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
