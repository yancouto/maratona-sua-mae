#include <cstdio>

int main() {
	int t, x;
	int a[60];
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int num = 0;
		for(int i = 0; i < n; i++)
			num ^= (a[i] - 1);
		if(num) puts("John");
		else puts("Brother");
	}
	return 0;
}