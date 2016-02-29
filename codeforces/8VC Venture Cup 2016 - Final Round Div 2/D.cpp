#include <bits/stdc++.h>

using namespace std;

#define MAXN 300000

int n, k, a, b, q;
struct bit {
	long long f[MAXN+5];
	bit() {
		for (int i = 0; i <= MAXN; ++i)
			f[i] = 0;
	}
	long long query(int x) {
		long long ret = 0;
		for (; x; x-=x&(-x)) {
			ret += f[x];
		}
		return ret;
	}
	void update(int x, int v) {
		for (; x <= MAXN; x+=x&(-x)) {
			f[x] += v;
		}
	}
};

int main() {
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	bit bef, aft;
	for (int itq = 0; itq < q; ++itq) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			int d, v;
			scanf("%d%d", &d, &v);
			int bf = bef.query(d)-bef.query(d-1);
			bef.update(d, min(v,b-bf));
			int af = aft.query(d)-aft.query(d-1);
			aft.update(d, min(v,a-af));
		}
		else {
			int p;
			scanf("%d", &p);
			long long bf = bef.query(p-1);
			long long af = aft.query(n)-aft.query(p+k-1);
			long long ans = bf + af;
			/* printf("%d %d\n", n, p+k-1); */
			/* printf("%d %d\n", bf, af); */
			printf("%I64d\n", ans);
		}
	}
}
