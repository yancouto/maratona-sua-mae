// MLE
#include <cstdio>
#include <cstdlib>
using namespace std;
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
const double c = 1.2;

int sz[1001], us[1001];
int *v[1001];
char op[10];

int main() {
	for(int i = 1; i <= 1000; i++)
		v[i] = (int*) malloc(sizeof(int) * 1),
		sz[i] = 1;
	int a;
	for_tests(t, tt) {
		scanf("%s %d", op, &a);
		if(op[1] == 'U') {
			if(sz[a] == us[a]) {
				sz[a] = int(sz[a] * c + .99);
				v[a] = (int*) realloc(v[a], sizeof(int) * sz[a]);
			}
			scanf("%d", &v[a][us[a]++]);
		} else {
			printf("%d\n", v[a][--us[a]]);
		}
	}
}
