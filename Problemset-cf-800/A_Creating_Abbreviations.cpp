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
  set<char> st;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    st.insert(str[0]);
  }
  bool found = true;
  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
      char foo = str[i] + 32;
      if (!st.count(foo)) {
        found = false;
      }
    }
  }
  if (found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
