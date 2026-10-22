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
  int foo = 0;
  int bar = 0;
  for (char a : str) {
    if (a == '0') {
      foo++;
    } else {
      bar++;
    }
  }
  string t;
  for (char a : str) {
    if (a == '0' and bar > 0) {
      t += '1';
      bar--;
    } else if (a == '1' and foo > 0) {
      t += '0';
      foo--;
    } else {
      t += a;
    }
  }
  //   cout << t << endl;
  int i = 0;
  int j = 0;
  int ans = 0;
  int sz = str.size();
  int tz = t.size();
  while (j != tz) {
    if (str[i] != t[j]) {
      i++;
      j++;
    } else {
      j++;
      ans++;
    }
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
