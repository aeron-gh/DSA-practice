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

// size(small to large) / rank and path compression and simple graph and leader
// array technique;
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
  ll n, m;
  cin >> n >> m;
  dsu dsu(n + 1);

  while (m--) {
    string str;
    ll a, b;
    cin >> str >> a >> b;
    if (str == "union") {
      dsu.unite(a, b);
    } else {
      if (dsu.checksame(a, b)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
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
