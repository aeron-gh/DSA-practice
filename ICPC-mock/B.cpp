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
  int n, d;
  cin >> n >> d;
  if (n == 0 and d == 0) {
    return;
  }
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int pos = arr[0] + d;
  int cnt = 1;

  for (int i = 1; i < n; i++) {
    int a = arr[i];
    if (a - d <= pos) {
    } else {
      pos = a + d;
      cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 200;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
