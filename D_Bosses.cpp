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

// weighted dsu: dist[x] = steps from x up to parent[x]
// after root(x), parent[x] is the top boss, so dist[x] = number of bosses
class dsu {
  vector<int> parent;
  vector<int> dist;

public:
  dsu(int n) {
    parent.resize(n);
    dist.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      dist[i] = 0;
    }
  }

  int root(int x) {
    if (parent[x] == x) {
      return x;
    }
    int r = root(parent[x]);
    // now dist[parent[x]] = steps from parent to top, so add it
    dist[x] += dist[parent[x]];
    parent[x] = r;
    return r;
  }

  // a goes under b (both are top bosses of their groups)
  void unite(int a, int b) {
    parent[a] = b;
    dist[a] = 1;
  }

  int bosses(int x) {
    root(x);
    return dist[x];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b;
      cin >> a >> b;
      d.unite(a, b);
    } else {
      int c;
      cin >> c;
      cout << d.bosses(c) << '\n';
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
