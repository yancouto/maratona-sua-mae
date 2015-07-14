#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
	int n, k, c;
	int a[55];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	c = 0;
	for (int j = n-1; j >= 0 && c < k; j--) {
		for (int i = j; i >= 0 && c < k; i--) {
			printf("%d ", n-j);
			for (int l = n-1; l > j; l--)
				printf("%d ", a[l]);	
			printf("%d\n", a[i]);
			c++;
		}
	}	
	return 0;
}


