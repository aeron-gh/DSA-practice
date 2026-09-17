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
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
  }
  vector<pair<string, pair<int, int>>> vec(k);
  for (int i = 0; i < k; i++) {
    string str;
    int a, b;
    cin >> str >> a >> b;
    vec[i].first = str;
    vec[i].second.first = a;
    vec[i].second.second = b;
  }

  DSU dsu(n);
  for (int i = k - 1; i >= 0; i--) {
    int foo = vec[i].second.first;
    int bar = vec[i].second.second;
    if (vec[i].first == "ask") {
      if (dsu.same(foo, bar)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      dsu.unite(foo, bar);
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
