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
  map<int, int> arr;
  int foo = 0;
  int bar = 0;
  int gar = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 1) {
      foo++;
    } else if (a % 4 == 0) {
      bar++;
    } else if (a % 4 != 0) {
      gar++;
    }
    arr[a]++;
  }

  int ans = 0;
  ans = max({foo, bar, gar});
  for (auto i : arr) {
    ans = max(ans, i.second);
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
