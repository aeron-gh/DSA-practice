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
  cin >> n;
  int ans = 0;
  int a;
  cin >> a;
  vector<int> arr;

  for (int i = 1; i < n; i++) {
    int b;
    cin >> b;
    if (i == n - 1) {
      arr.push_back(b);
      ans++;
    }
    if (a < b) {
      a = b;
      continue;
    } else {
      arr.push_back(a);
      a = b;
      ans++;
    }
  }
  cout << ans << endl;
  for (auto a : arr) {
    cout << a << " ";
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
