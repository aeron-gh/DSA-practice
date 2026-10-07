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
  int n;
  char c;
  string str;
  cin >> n >> c >> str;
  int i = 0;
  int j = n - 1;
  int ans = 0;
  while (i < j) {
    if (str[i] != str[j]) {
      if (str[i] == c or str[j] == c) {
        ans++;
      } else {
        ans += 2;
      }
    }
    i++;
    j--;
  }
  cout << ans << endl;
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
