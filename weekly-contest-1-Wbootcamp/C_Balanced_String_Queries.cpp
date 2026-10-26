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
  int n, q;
  cin >> n >> q;
  vector<int> vec(n);
  vector<int> a(n);
  vector<int> b(n);

  int foo = 0;
  int bar = 0;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    int num = c - '0';
    vec[i] = num;
    if (vec[i] == 0) {
      foo++;
    } else {
      bar++;
    }
    a[i] = foo;
    b[i] = bar;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    if (l == 0) {
      if (a[r] == b[r]) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if ((a[r] - a[l - 1]) == (b[r] - b[l - 1])) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
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
