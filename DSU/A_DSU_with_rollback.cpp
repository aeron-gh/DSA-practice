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

// path compression not possible
class dsu {
  vector<ll> parent;
  vector<ll> size;
  stack<pair<ll, ll>> his;

public:
  int com;
  dsu(ll n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
    com = n - 1;
  }

  bool checksame(ll x, ll y) { return root(x) == root(y); }
  int root(ll x) {
    if (parent[x] == x) {
      return x;
    }
    return root(parent[x]);
  }

  void unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (size[x] > size[y]) {
      swap(x, y);
    }
    his.push({y, x});
    if (x == y) {
      return;
    }
    parent[x] = y;
    size[y] += size[x];
    com--;
  }

  void per() { his.push({-1, -1}); }

  void rollback() {
    while (!his.empty()) {
      auto [y, x] = his.top();
      his.pop();
      if (x == -1 and y == -1) {
        return;
      }
      if (x == y) {
        continue;
      }
      parent[x] = x;
      size[y] += size[x];
      com++;
    }
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;
  dsu dsu(n + 1);

  while (m--) {
    string str;
    ll a, b;
    cin >> str;
    if (str == "union") {
      cin >> a >> b;
      dsu.unite(a, b);
      cout << dsu.com << endl;
    } else if (str == "persist") {
      dsu.per();
    } else {
      dsu.rollback();
      cout << dsu.com << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
