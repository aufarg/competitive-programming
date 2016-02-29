#include <bits/stdc++.h>

using namespace std;

struct node {
	node* ch[26];
	char v;
	int idx;
};

void node_init(node *n) {
	for (int i = 0; i < 26; ++i)
		n->ch[i] = NULL;
	n->idx = -1;
}

#define MAXM 100000
string orig[MAXM+5];
int p[MAXM+5];
int c[MAXM+5];

int main() {
	int n, m;
	string s;
	scanf("%d", &n);
	cin >> s;
	scanf("%d", &m);
	node root;
	node_init(&root);
	for (int i = 0; i < m; ++i) {
		string dum;
		cin >> dum;
		orig[i] = dum;
		node *cur = &root;
		for (int j = (int)dum.size()-1; j >= 0 ; --j) {
			int cv = tolower(dum[j])-'a';
			if (cur->ch[cv] == NULL) {
				cur->ch[cv] = (node*)malloc(sizeof(node));
				node_init(cur->ch[cv]);
				cur->ch[cv]->v = dum[j];
			}
			cur = cur->ch[cv];
		}
		cur->idx = i;
	}
	memset(p, -1, sizeof(p));
	memset(c, -1, sizeof(c));
	for (int i = 0; i < n; ++i) {
		if (i && p[i] < 0) continue;
		node *cur = &root;
		for (int j = 0; cur != NULL && j < 1000 && i+j < n; ++j) {
			cur = cur->ch[tolower(s[i+j])-'a'];
			if (cur != NULL && cur->idx >= 0) {
				p[i+j+1] = i;
				c[i+j+1] = cur->idx;
				assert(cur->idx >= 0);
			}
		}
	}

	int kp = n;
	vector<int> ans;
	while (c[kp] >= 0) {
		ans.push_back(c[kp]);
		kp = p[kp];
	}
	for (int i = (int)ans.size()-1; i >= 0; --i) {
		if (i != (int)ans.size()-1) cout << " ";
		cout << orig[ans[i]];
	}
	cout << endl;
}
