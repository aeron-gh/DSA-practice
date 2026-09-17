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

class DSU {
public:
  vector<int> leader;
  vector<vector<int>> component;
  DSU(int n) {
    leader.resize(n + 1);
    component.resize(n + 1);

    for (int i = 1; i <= n; i++) {
      leader[i] = i;
      component[i].push_back(i);
    }
  }

  void unite(int u, int v) {
    int lu = leader[u];
    int lv = leader[v];

    if (lu == lv)
      return;

    if (component[lu].size() < component[lv].size())
      swap(lu, lv);

    for (int x : component[lv]) {
      leader[x] = lu;
      component[lu].push_back(x);
    }

    component[lv].clear();
  }

  bool same(int u, int v) { return leader[u] == leader[v]; }
};

void solve() {
  int n, m;
  cin >> n >> m;
  DSU dsu(n);

  while (m--) {
    string str;
    int a, b;
    cin >> str >> a >> b;
    if (str == "union") {
      dsu.unite(a, b);
    } else {
      if (dsu.same(a, b)) {
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
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
