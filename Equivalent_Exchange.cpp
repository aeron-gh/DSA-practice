#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v;
        int p = 0;
        int foo = 0, bar = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if(i == 0){if(a>0){p=1;}else{p = 0;};}
                  
                if(p == 0){
                    if(a > 0){
                        v.push_back(foo);
                        foo = 0; 
                        foo += a;
 
                    }else{
                        foo += a;
                    }
                }
                else if(p == 1){
                      if(a > 0){
                           foo += a;
                    }else{
                        v.push_back(foo);
                        foo = 0; 
                        foo += a;
                    }  
                }

            if(a > 0){
                p = 1;
            }else{
                p = 0;
            }
            
        }
        v.push_back(foo);
        foo = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > 0){
               if(abs(v[i]) > foo){
                    foo = abs(v[i]);
               }
            }else{
                if(abs(v[i]) > bar){
                    bar = abs(v[i]);
               }
            }
        }
        cout << foo << " " << bar << endl;
    }

    return 0;
}