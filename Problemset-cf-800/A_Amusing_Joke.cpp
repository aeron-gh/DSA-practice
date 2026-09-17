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
  map<char, int> mp;
  vector<int> arr(26, 0);
  vector<int> arrp(26, 0);

  for (int i = 0; i < 2; i++) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
      arr[str[i] - 'A']++;
    }
  }
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    arrp[str[i] - 'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (arr[i] != arrp[i]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
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
