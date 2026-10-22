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
  int i = 0;
  int j = n - 1;
  while (i <= j) {
    if (str[i] == '1' and str[j] == '1') {
      break;
    }
    if (str[i] == '0' and str[j] == '0') {
      break;
    }
    i++;
    j--;
  }
  if (i == j and n % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << j - i + 1 << endl;
  }
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
