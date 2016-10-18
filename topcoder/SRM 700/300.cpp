#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
class FindingFriend {
    public:
        int find(int size, vector<int> lead, int f) {
            int n = lead.size();
            int pn = n * size;
            sort(lead.begin(), lead.end());
            int ans = 0;
            for (int i = n-1; i >= 0; --i) {
                if (lead[i] == f) return 1;
                if (lead[i] > f) continue;
                ++ans;
                int idx = n-i;
                if (pn-lead[i] < idx*size) break;
            }
            return ans;
        }
};
