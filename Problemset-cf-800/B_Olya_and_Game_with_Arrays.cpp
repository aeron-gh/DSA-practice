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
  int n;
  cin >> n;
  int j = n;
  vector<int> p;
  vector<int> q;
  while (j--) {
    int m;
    cin >> m;
    vector<int> v;
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    q.push_back(v[1]);
    for (int i = 0; i < 2; i++) {
      p.push_back(v[i]);
    }
  }

  sort(p.begin(), p.end());
  int ans = p[0];

  sort(q.begin(), q.end());
  reverse(q.begin(), q.end());
  for (int i = 0; i < q.size() - 1; i++) {
    ans += q[i];
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
