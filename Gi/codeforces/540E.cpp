#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Swap {
	int a, b;
};

int n, ir = 0, iR;
int r[200005], v[200005];
long long bit[200005];
Swap s[100005];
map<int,int> mapa;

void update(int value) {
	for (int i = value; i <= iR; i+=(i)&(-i))
		bit[i]++;
}

long long get(int value) {
	long long ret = 0;
	for (int i = value; i > 0; i-=(i)&(-i))
		ret += bit[i];
	return ret;
}

int main () {
	scanf("%d", &n);
	int i;
	ir = 1;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &s[i].a, &s[i].b);
		r[ir++] = s[i].a;
		r[ir++] = s[i].b;
	}	
	sort(r+1, r + ir);
	
	iR = 2;
	v[1] = 1;
	mapa.insert(pair<int,int>(r[1], 1));
	for (i = 2; i < ir; i++) {		
		if (r[i] != r[i-1]) {
			v[iR] = iR;
			mapa.insert(pair<int,int>(r[i], iR));
			r[iR++] = r[i];
		}
	}
	for (i = 0; i < n; i++) {
		int a, b;
		a = mapa.find(s[i].a)->second;
		b = mapa.find(s[i].b)->second;
		int aux = v[a];
		v[a] = v[b];
		v[b] = aux;
	}
	long long ans = 0;
	for (i = 1; i < iR; i++) {
		update(v[i]);
		int m = min(i, v[i]);
		ans += r[i]-get(v[i])-(r[m]-m);

		if (i != iR-1 && r[i+1] - r[i] > 1) {
			ans += (i-get(i))*(r[i+1]-r[i]-1);
		}
		
	}
	printf("%lld\n", ans);
	return 0;
}

//http://codeforces.com/contest/540/problem/E