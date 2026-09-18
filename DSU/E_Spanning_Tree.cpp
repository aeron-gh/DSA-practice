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

class dsu {
  vector<ll> parent;
  vector<ll> size;

public:
  dsu(ll n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  bool checksame(ll x, ll y) { return root(x) == root(y); }
  int root(ll x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = root(parent[x]);
  }

  void unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    if (size[x] > size[y]) {
      swap(x, y);
    }
    parent[x] = y;
    size[y] += size[x];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vec[i] = {c, a, b};
  }

  dsu ds(n + 1);
  sort(vec.begin(), vec.end());
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (ds.checksame(vec[i][1], vec[i][2])) {

    } else {
      ans += vec[i][0];
      ds.unite(vec[i][1], vec[i][2]);
    }
  }
  cout << ans;
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
