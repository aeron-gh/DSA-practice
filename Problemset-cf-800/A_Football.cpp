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
  string str;
  cin >> str;
  int a = 1;
  int ans = 1;
  for (int i = 0; i < str.size() - 1; i++) {
    if (str[i] == str[i + 1]) {
      a++;
      ans = max(ans, a);
    } else {
      a = 1;
    }
  }
  ans = max(ans, a);
  if (ans >= 7) {
    cout << "YES";
  } else {
    cout << "NO";
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
