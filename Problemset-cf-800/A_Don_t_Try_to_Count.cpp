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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int times = 6;
  bool found = false;
  while (times--) {
    if (s.find(t) != std::string::npos) {
      found = true;
      break;
    } else {
      s += s;
    }
  }
  if (!found) {
    cout << -1 << endl;
    return;
  }
  cout << 5 - times << endl;
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
