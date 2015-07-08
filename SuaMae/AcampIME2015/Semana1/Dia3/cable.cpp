#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
using namespace std;

int n, x[1003], y[1003];
struct st {
	int a, b;
	double d;
	bool operator < (const st &o) const { return d < o.d; }
} es[1000003];
int e;

int S[1003], size[1003];
double tot[1003];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i]; 
}
void join(int a, int b, double d) {
	if(a == b) return;
	if(size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	tot[a] += tot[b] + d;
	S[b] = a;
}

int main() {
	int i, j;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 0; i < n; i++) {
			S[i] = i;
			size[i] = 1;
			tot[i] = 0;
			scanf("%d %d", &x[i], &y[i]);
		}
		e = 0;
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n; j++) {
				es[e].a = i;
				es[e].b = j;
				es[e++].d = sqrt((x[i] - x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
			}
		sort(es, es + e);
		for(i = 0; i < e; i++)
			join(find(es[i].a), find(es[i].b), es[i].d);
		printf("%.2f\n", tot[find(0)]);
	}
}