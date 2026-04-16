#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>

class OrderedSet
{
private:
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> st;

public:
    int countElementsLessThanX(T x)
    {
        return st.order_of_key(x + 1);
    }

    int countElementsAtleastX(T x)
    {
        return st.size() - countElementsLessThanX(x);
    }

    T getKthElement(int k)
    {
        if (k <= 0 || k > size())
        {
            return -1;
        }
        return *st.find_by_order(k);
    }

    void insert(T x)
    {
        st.insert(x);
    }

    void erase(T x)
    {
        st.erase(x);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    OrderedSet<int> st;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.insert(a);
    }

    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 0)
        {
            st.insert(x);
        }
        else if (t == 1)
        {
            st.erase(x);
        }
        else if (t == 2)
        {
            cout << st.getKthElement(x) << endl;
        }
        else if (t == 3)
        {
            cout << st.countElementsLessThanX(x) + 1 << endl;
        }
        else if (t == 4)
        {
            int a = st.countElementsAtleastX(x);
            cout << st.getKthElement(a) << endl;
        }
        else
        {
            int a = st.countElementsAtleastX(x) + 1;
            cout << st.getKthElement(a) << endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl "\n"

template <typename T>
class OrderedSet {
private:
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> st;

public:
    int countElementsLessThanX(T x) {
        return st.order_of_key(x);
    }

    int countElementsAtleastX(T x) {
        return st.size() - st.order_of_key(x);
    }

    T getKthElement(int k) {
        if (k < 0 || k >= st.size()) return -1;
        return *st.find_by_order(k);
    }

    void insert(T x) {
        st.insert(x);
    }

    void erase(T x) {
        st.erase(x);
    }

    int size() {
        return st.size();
    }
};

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}