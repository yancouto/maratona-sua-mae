#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100009;

int main() {
	int n;
	int c = 0;
	while (true) {
		scanf("%d", &n);
		if (n == 0) return 0;
		int t, nt;
		t = nt = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			if (a == 0) t++;
			else nt++;
		}
		printf("Case %d: %d\n", ++c, nt - t);
	}
	return 0;
}