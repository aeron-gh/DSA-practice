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
  int ans = 0;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first;
    cin >> vec[i].second;
  }
  for (int i = 0; i < n; i++) {
    int a, b;
    a = vec[i].first;
    b = vec[i].second;
    for (int j = i + 1; j < n; j++) {
      int foo, bar;
      foo = vec[j].first;
      bar = vec[j].second;
      if (a == bar) {
        ans++;
        // cout << foo << " " << bar << endl;
      }
      if (b == foo) {
        ans++;
        // cout << foo << " " << bar << endl;
      }
    }
  }
  cout << ans;
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
