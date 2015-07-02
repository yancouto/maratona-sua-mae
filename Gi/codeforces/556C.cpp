#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct Elem {
	int ind, value;
	Elem(int ind, int value) : ind(ind), value(value) {}
	Elem() {}
};

bool myfunction(Elem a, Elem b) {
	return a.value < b.value;
}

int n, k;
int usado[100005], tam[100005];
Elem e[100005];

int find (int pos) {
	int ind = e[pos].ind;
	int i;
	for (i = pos + 1; i < n && ind == e[i].ind; i++);
	return i;
}

int main () {
	int ind = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int m;
		scanf("%d", &m);
		tam[i] = m;
		for (int j = 0; j < m; j++) {
			int a;
			scanf("%d", &a);
			e[ind].ind = i;
			e[ind++].value = a;
		}
	}
	sort(e, e + n, myfunction);
	usado[e[0].ind] = 1;
	int i = find(0);
	int tme = tam[e[0].ind]-i;
	for (int i = find(0); i < n; i++) {
		if (usado[e[i].ind]) {
			tme++;
		}
		else {
			usado[e[i].ind] = 1;
			tme += tam[e[i].ind];
		}
	}
	printf("%d\n", tme);
	return 0;
}