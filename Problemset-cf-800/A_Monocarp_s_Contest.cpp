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
  int arr[n];
  int no = 0;
  for (int &a : arr) {
    cin >> a;
  }
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] == 0) {
      no++;
    }
  }
  int ans = 0;
  if (arr[0] == 1) {
    if (no - 1 < 0) {
      cout << -1 << endl;
      return;
    }
    no--;
    ans++;
  }
  if (arr[n - 1] == 1) {
    if (no - 1 < 0) {
      cout << -1 << endl;
      return;
    }
    no--;
    ans++;
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
