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
  int fa, fb, a, b, c, d;
  cin >> fa >> fb >> a >> b >> c >> d;
  vector<pair<int, int>> f = {{fa, fb}, {-fa, -fb}, {fa, -fb}, {-fa, fb},
                              {fb, fa}, {-fb, -fa}, {-fb, fa}, {fb, -fa}};

  set<pair<int, int>> v1;
  set<pair<int, int>> v2;
  for (int i = 0; i < 8; i++) {
    v1.insert({a + f[i].first, b + f[i].second});
    v2.insert({c + f[i].first, d + f[i].second});
  }
  int ct = 0;
  for (auto a : v2) {
    if (v1.count(a)) {
      ct++;
    }
  }
  cout << ct << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
