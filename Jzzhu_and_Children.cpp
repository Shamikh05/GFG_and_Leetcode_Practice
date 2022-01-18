#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

        int n, m;
        cin >> n >> m;

        queue<pair<int, int> > q;

        for(int i=0;i<n;++i) {

                int candies;
                cin >> candies;

                q.push({candies,i+1});
        }

        int ans = 0;

        while(!q.empty()) {

                auto kid = q.front();

                if(m < kid.first) {
                        kid.first -= m;
                        q.pop();
                        q.push(kid);
                }
                else
                        q.pop();

                ans = kid.second;
        }

        cout << ans << endl;

        return 0;
}
