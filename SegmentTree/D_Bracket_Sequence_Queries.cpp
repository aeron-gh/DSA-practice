#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

struct Node {
  int ans = 0;
  int o = 0;
  int c = 0;
};

Node operator+(Node a, Node b) {
  Node node;

  int paired = 2 * min(a.o, b.c);

  node.ans = a.ans + b.ans + paired;
  node.o = a.o + b.o - (paired / 2);
  node.c = a.c + b.c - (paired / 2);

  return node;
}

template <typename T> struct SegTree {
  T *tree;
  const int n;
  const T identity;

private:
#define mid ((tL + tR) >> 1)
#define lcId ((tId << 1) + 1)
#define rcId lcId + 1
#define leftChild lcId, tL, tM
#define rightChild rcId, tM + 1, tR

  void update(int tId, int tL, int tR, int idx, T val) {
    if (tL == tR) {
      tree[tId] = val;
      return;
    }

    int tM = mid;

    if (idx <= mid)
      update(leftChild, idx, val);
    else
      update(rightChild, idx, val);

    tree[tId] = tree[lcId] + tree[rcId];
  }

  T query(int tId, int tL, int tR, int l, int r) {
    if (l > tR || r < tL)
      return identity;

    if (l <= tL && tR <= r)
      return tree[tId];

    int tM = mid;

    return query(leftChild, l, r) + query(rightChild, l, r);
  }

#undef mid
#undef lcId
#undef rcId
#undef leftChild
#undef rightChild

public:
  SegTree(int n, T identity) : n(n), identity(identity) {
    tree = new T[4 * n];

    for (int i = 0; i < 4 * n; ++i)
      tree[i] = identity;
  }

  void update(int idx, T val) { update(0, 0, n - 1, idx, val); }

  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

void solve() {
  int n, m;
  cin >> n >> m;

  char a[n];

  for (auto &i : a) {
    cin >> i;
  }

  SegTree<Node> st(n, Node());

  for (int i = 0; i < n; i++) {
    if (a[i] == '(') {
      st.update(i, Node({0, 1, 0}));
    } else {
      st.update(i, Node({0, 0, 1}));
    }
  }

  while (m--) {
    int t;
    cin >> t;

    if (t == 1) {
      int i;
      char val;

      cin >> i >> val;
      i--;

      if (val == '(') {
        st.update(i, Node({0, 1, 0}));
      } else {
        st.update(i, Node({0, 0, 1}));
      }
    } else {
      int l, r;

      cin >> l >> r;

      l--;
      r--;

      cout << st.query(l, r).ans << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;

  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
