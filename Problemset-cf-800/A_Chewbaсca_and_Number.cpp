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
  string s;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (i == 0 and ch == '9') {
      s += '9';
      continue;
    }
    int a = ch - '0';
    if (a >= 5) {
      a = 9 - a;
    }
    s += (char)(a + '0');
  }
  cout << s;
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
