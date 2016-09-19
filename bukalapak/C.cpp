#include<stdio.h>
#include<string.h>
 
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int v = i*n+j+1;
			if (j) printf(" ");
			printf("%d", v);
		}
		printf("\n");
	}
}
