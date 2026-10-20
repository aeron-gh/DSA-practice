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
bool prime(int n) {
  if (n < 2) {
    return false;
  }
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      if (n % i == 0) {
        cnt += 1;
      }
    } else {
      if (n % i == 0) {
        cnt += 2;
      }
    }
  }
  if (cnt <= 2) {
    return true;
  } else {
    return false;
  }
}
bool rprime(string str) {
  int n = stoll(str);
  if (n < 2) {
    return false;
  }
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (i * i == n) {
      if (n % i == 0) {
        cnt += 1;
      }
    } else {
      if (n % i == 0) {
        cnt += 2;
      }
    }
  }
  if (cnt <= 2) {
    return true;
  } else {
    return false;
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    string r = to_string(i);
    reverse(r.begin(), r.end());
    if (prime(i) and rprime(r)) {
      ans++;
    }
  }
  cout << ans;
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
