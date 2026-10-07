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
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  int a = s.size() - 1;
  int b = t.size() - 1;
  if (a < b) {
    for (int i = a; i >= 0; i--) {
      if (s[i] == t[b]) {
        cnt++;
        b--;
      } else {
        break;
      }
    }
  } else {
    for (int i = b; i >= 0; i--) {
      if (s[a] == t[i]) {
        cnt++;
        a--;
      } else {
        break;
      }
    }
  }
  //   cout << cnt << " ";
  cout << s.size() + t.size() - (2 * cnt);
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
