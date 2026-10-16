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
  string str;
  cin >> str;
  int foo = 0;
  int bar = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '<') {
      foo++;
    } else {
      bar = max(foo, bar);
      foo = 0;
    }
  }
  bar = max(foo, bar);

  int fo = 0;
  int ba = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '>') {
      fo++;
    } else {
      ba = max(fo, ba);
      fo = 0;
    }
  }
  ba = max(fo, ba);

  cout << max(ba, bar) + 1 << endl;
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
