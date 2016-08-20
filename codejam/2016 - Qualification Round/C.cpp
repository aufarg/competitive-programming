#include <bits/stdc++.h>

using namespace std;


long long base(vector<int> repre, long long b)
{
	long long ret = 0;
	for (int i = 0; i < (int)repre.size(); ++i) {
		ret = ret * b + repre[i];
	}
	return ret;
}

int isprime(long long a) {
	for (long long i = 2; i*i <= a; ++i) {
		if (a % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int n, j;
		scanf("%d%d", &n, &j);
		set<string> done;
		printf("Case #%d:\n", itc);
		for (int l = 4; l <= 16 && j; ++l) {
			if (n % l != 0) continue;
			// starting and ending with 1
			for (int b = 0; b < (1<<(l-2)) && j; ++b) {
				vector<int> repre;
				repre.push_back(1);
				for (int i = 0; i < l-2; ++i)
					repre.push_back( (b&(1<<i)) ? 1 : 0);
				repre.push_back(1);

				int fail = 0;
				for (int i = 2; i <= 10; ++i)
					if (isprime(base(repre,i))) fail = 1;

				if (!fail) {
					string srepre = "";
					for (int t = 0; t < n / l; ++t) {
						for (int i = 0; i < (int)repre.size(); ++i)
							srepre += (char)(repre[i]+48);
					}
					if (done.find(srepre) != done.end()) continue;
					done.insert(srepre);
					cout << srepre;
					printf(" ");
					for (int i = 2; i <= 10; ++i) {
						if (i > 2) printf(" ");
						printf("%lld", base(repre, i));
					}
					printf("\n");
					--j;
				}
			}
		}
	}
}
