#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int w, l;

double calc (int x){
	if (x <= 10000){
		double ret = 0;
		for (int i = 1; i <= x; i++) ret += (1./i);
		return ret;
	}
	return log(x);
}

int main() {
	int i, t = 0;

	while(true) {
		scanf("%d %d", &w, &l);
		t++;
		if(w == 0 && l == 0) return 0;
		int c = w/8;
		int dd = max((w - 7*l + 7) / 8, 0);
		printf("Case %d:\n", t);
		if(l == 0 && (w % 8)) { puts("Situation Impossible."); continue; }
		printf("On Average Bob Reaches Round ");
		if(l == 0) { puts("8.00"); continue; }
		double d = 0;
		printf("%.2f\n", double(w + l) * (calc(l + c) - calc(l + dd - 1)) / (c - dd + 1));
	}
}