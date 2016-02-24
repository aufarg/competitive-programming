#include <bits/stdc++.h>

using namespace std;

#define MAXL 100

int todec(char *b, int l) {
	int ret = 0;
	int next = 1;
	for (int i = 0; i < l; ++i) {
		if ('2' <= b[i] && b[i] <= '9') {
			next = b[i]-'0';
		}
		else {
			int v;
			switch (b[i]) {
				case 'm': v = 1000; break;
				case 'c': v = 100; break;
				case 'x': v = 10; break;
				case 'i': v = 1; break;
				default: assert(false);
			}
			ret += next * v;
			next = 1;
		}
	}
	return ret;
}

void addbuf(char c, int cnt, char *buf) {
	if (cnt > 1) {
		buf[0] = char(cnt + int('0'));
		buf[1] = c;
		buf[2] = 0;
	}
	else if (cnt == 1) {
		buf[0] = c;
		buf[1] = 0;
	}
	else {
		buf[0] = 0;
	}
}
void conv(int sum, char *buf) {
	int mnx = sum / 1000;
	sum -= 1000 * mnx;
	int cnx = sum / 100;
	sum -= 100 * cnx;
	int xnx = sum / 10;
	sum -= 10 * xnx;
	int inx = sum / 1;

	char sbuf[MAXL+5];
	*buf = 0;
	addbuf('m', mnx, sbuf);
	strcat(buf, sbuf);
	addbuf('c', cnx, sbuf);
	strcat(buf, sbuf);
	addbuf('x', xnx, sbuf);
	strcat(buf, sbuf);
	addbuf('i', inx, sbuf);
	strcat(buf, sbuf);
}

char buf1[MAXL+5], buf2[MAXL+5], ans[MAXL+5];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s", buf1, buf2);
		int n1 = strlen(buf1);
		int n2 = strlen(buf2);
		int r1 = todec(buf1, n1);
		int r2 = todec(buf2, n2);
		conv(r1+r2, ans);
		printf("%s\n", ans);
	}
	return 0;
}
