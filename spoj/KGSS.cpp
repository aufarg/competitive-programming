#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000
int n;
int a[MAXN+5];

typedef struct seg_s {
	int l, r;
	int val, idx;
	seg_s *lch, *rch;
} segtree;

typedef struct {
	int val, idx;
} segres;

segtree *build(int l, int r) {
	segtree *node = (segtree *)malloc(sizeof(segtree)); 
	node->l = l;
	node->r = r;
	node->val = a[l];
	node->idx = l;
	node->lch = NULL;
	node->rch = NULL;

	if (l != r) {
		int m = (l+r)/2;
		node->lch = build(l, m);
		node->rch = build(m+1, r);

		// update value
		segres lres;
		lres.val = node->lch->val;
		lres.idx = node->lch->idx;
		segres rres;
		rres.val = node->rch->val;
		rres.idx = node->rch->idx;

		if (lres.val > rres.val) {
			node->val = lres.val;
			node->idx = lres.idx;
		}
		else {
			node->val = rres.val;
			node->idx = rres.idx;
		}
	}

	return node;
}

void update(segtree *node, int x, int val) {
	if (node->l == node->r) {
		if (node->l == x) {
			node->val = val;
		}
	}
	else {
		if (node->l <= x && x <= node->r) {
			update(node->lch, x, val);
			update(node->rch, x, val);

			segres lres;
			lres.val = node->lch->val;
			lres.idx = node->lch->idx;
			segres rres;
			rres.val = node->rch->val;
			rres.idx = node->rch->idx;

			if (lres.val > rres.val) {
				node->val = lres.val;
				node->idx = lres.idx;
			}
			else {
				node->val = rres.val;
				node->idx = rres.idx;
			}
		}
	}

}

segres query(segtree *node, int l, int r) {
	//printf("%d %d\n", node->l, node->r);
	if (l <= node->l && node->r <= r) {
		segres ret;
		ret.val = node->val;
		ret.idx = node->idx;
		return ret;
	}
	else {
		if (node->r < l || r < node->l) {
			segres ret;
			ret.val = -1;
			ret.idx = node->idx;
			return ret;
		}
		else {
			segres lres = query(node->lch, l, r);
			segres rres = query(node->rch, l, r);

			if (lres.val > rres.val) return lres;
			else return rres;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	segtree *node = build(1, n);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		char buf[8];
		scanf("%s", buf);
		if (buf[0] == 'U') {
			int x, val;
			scanf("%d%d", &x, &val);
			update(node, x, val);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			segres fmax = query(node, l, r);
			int tmp = fmax.val;
			update(node, fmax.idx, -1);
			segres smax = query(node, l, r);
			update(node, fmax.idx, tmp);

			//printf("%d %d\n", fmax.val, smax.val);
			printf("%d\n", fmax.val + smax.val);
		}
	}

	return 0;
}
