#include <cstdio>
int n;
int a[100];

int memo1[102][1026];
bool simple(int t, int x) {
	int &m = memo1[t][x];
	if(m != 0)
		return m == 1;
	if(t == 100) { m = 2; return false; }
	if(t < 10 && (x & (1 << t))) { m = 1; return true; }
	if(t >= 10 && (x & (1 << (t % 10))) && (x & (1 << (t / 10))) && ((t % 10) != (t / 10))) { m = 1; return true; }
	m = 2;
	return false;
}

int memo2[102][1026];
bool pos(int t, int x) {
	int &m = memo2[t][x];
	if(m != 0)
		return m == 1;
	if(simple(t, x)) {
		m = 1;
		return true;
	}
	for(int i = 1; i < ((t + 1) / 2); i++) {
		int o = t - i;
		if((i % 10) == (o % 10)) continue;
		if(i >= 10 && (i / 10) == (o % 10)) continue;
		if(o >= 10 && (i % 10) == (o / 10)) continue;
		if(i >= 10 && o >= 10 && (i / 10) == (o / 10)) continue;
		// printf("%d = %d + %d\n", t, i, o);
		if(simple(i, x) && simple(o, x)) { m = 1; return true; }
	}
	m = 2;
	return false;
}

bool pos(int x) {
	for(int i = 0; i < n; i++) {
		// printf("i %d\n", i);
		if(!pos(a[i], x)) {
			// printf("%d bad!\n", a[i]);
			return false;
		}
	}
	return true;
}

int main() {
	int i, j;
	for(int tt = 1;; tt++) {
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int min_d = 11, min_x;
		for(i = 1; i < 1024; i++) {
			// printf("iii %d\n", i);
			if(!pos(i)) continue;
			int count = 0;
			for(j = 0; j < 10; j++)
				if(i & (1 << j))
					count++;
			// printf("%d\n", count);
			if(count < min_d) {
				min_d = count;
				min_x = i;
			}
		}
		printf("Case %d: ", tt);
		for(j = 9; j >= 0; j--)
			if(min_x & (1 << j))
				putchar('0' + j);
		putchar('\n');
	}
}