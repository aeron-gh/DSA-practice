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
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (k == 1) {
    cout << -1 << endl;
    return;
  }
  int p = n - k;
  vector<bool> v(n, false);
  for (int i = 0; i <= p; i++) {
    v[arr[i]] = true;
  }
  int foo = -1;
  int bar = -1;
  for (int i = 0; i < n; i++) {
    if (!v[i] and foo == -1) {
      foo = i;
    } else if (v[i] and foo != -1) {
      bar = i;
    }
  }
  //   cout << foo << " " << bar << endl;
  int a = -1, b = -1;
  for (int i = 0; i <= p; i++) {
    if (arr[i] == bar) {
      a = i + 1;
    }
  }
  for (int i = p + 1; i < n; i++) {
    if (arr[i] == foo) {
      b = i + 1;
    }
  }
  if (a == -1 or b == -1) {
    cout << -1 << endl;
    return;
  }
  cout << a << " " << b << endl;
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
