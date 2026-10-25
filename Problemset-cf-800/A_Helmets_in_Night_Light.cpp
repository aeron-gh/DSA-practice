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
  int n, p;
  cin >> n >> p;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[i].first = a;
  }
  int foo = 0;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < p) {
      foo += v[i].first;
      vec.push_back({
          a,
          v[i].first,
      });
    }
    v[i].second = a;
  }
  int ans = p;
  //   int m = n;
  n--;
  sort(vec.begin(), vec.end());
  if (n - foo <= 0) {
    for (int i = 0; i < vec.size(); i++) {
      int b = n - vec[i].second;
      if (b >= 0) {
        n -= vec[i].second;
        ans += vec[i].first * vec[i].second;
        // if (n == 0) {
        //   break;
        // }
      } else {
        ans += n * vec[i].first;
        break;
      }
    }
  } else {
    for (int i = 0; i < vec.size(); i++) {
      ans += vec[i].first * vec[i].second;
    }
    ans += (n - foo) * p;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
