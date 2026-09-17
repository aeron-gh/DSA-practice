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
public:
  vector<int> parent;
  vector<int> size;
  vector<int> mn;
  vector<int> mx;

  dsu(int n) {
    parent.resize(n);
    size.resize(n);
    mn.resize(n);
    mx.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
      mn[i] = i;
      mx[i] = i;
    }
  }

  bool checksame(int x, int y) { return root(x) == root(y); }
  int root(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = root(parent[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    // if x -> smaller
    if (size[x] > size[y]) {
      swap(x, y);
    }
    parent[x] = y;
    size[y] += size[x];
    mn[y] = min(mn[y], mn[x]);
    mx[y] = max(mx[y], mx[x]);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  dsu dsu(n + 1);

  while (m--) {
    string str;
    int a, b;
    cin >> str;
    if (str == "union") {
      cin >> a >> b;
      dsu.unite(a, b);
    } else {
      int a;
      cin >> a;
      int foo = dsu.root(a);
      cout << dsu.mn[foo] << " " << dsu.mx[foo] << " " << dsu.size[foo] << endl;
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
