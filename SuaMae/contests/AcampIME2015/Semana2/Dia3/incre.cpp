#include <cstdio>

using namespace std;

const int MAX = 100000;

int main() {
	int n, v[MAX], sum;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		sum += v[i];	
	}
	int med = sum / n;
	for(int i = 1; i < n; i++) {
		int diff = med - v[i - 1];
		v[i] += -diff;
	}
	if(v[n - 1] == med) printf("%d\n", n);
	else printf("%d\n", n - 1);
	return 0;
}
