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

int ans = 0;
void f(int n) {
  ans++;
  if (n == 1) {
    return;
  }

  if (n % 2 == 0) {
    f(n / 2);
  } else {
    f((3 * n) + 1);
  }
}

void solve() {
  int n;
  cin >> n;
  f(n);
  cout << ans;
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
