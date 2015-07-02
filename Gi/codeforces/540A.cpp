#include <cstdio>
#include <algorithm>

using namespace std;

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main () {
	int n;
	int s[1005];
	scanf("%d", &n);
	char c;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		s[i] = c - '0';
	}
	int li, resp;
	resp = 0;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		li = c - '0';
		//printf("%d %d\n", s[i], li);
		if (s[i] > li) {
			resp += min(9-s[i] + li + 1, s[i]-li);
			//printf("gasto(%d)=%d\n", i, min(9-s[i] + li + 1, s[i]-li));
		}
		else if (s[i] < li) {
			resp += min(s[i] + 9 - li + 1, li-s[i]);
			//printf("gasto(%d)-%d\n", i, min(s[i] + 9 - li + 1, li-s[i]));
		}
	}
	printf("%d\n", resp);
	return 0;
}