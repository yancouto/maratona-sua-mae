#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int MAXL = 5000100;
const ull BASE = 71;

ull h[MAXL], r[MAXL];
ull pd[MAXL], pd2[MAXL];
char str[MAXL + 1];
int L;

ull val(char c) {
	if(c >= 'a' && c <= 'z') return c - 'a' + 1;
	else if(c >= 'A' && c <= 'Z') return c - 'A' + 30;
	else return c - '0' + 60;
}

ull diff(int a, int b, ull v[]) {
	if(a == 0) return v[b];
	else return v[b] - v[a - 1];
}

ull power(int base) {
	ull &ret = pd2[base];
	if(ret != -1) return ret;
	if(base == 0) return ret = 1;
	else if((base % 2) == 0){
		ull aux = power(base/2);
		return ret = aux*aux;
	} else {
		return ret = BASE*power(base - 1);
	}
}

bool pal(int i, int j) {
	ull diffA = diff(i, j, h), diffB = diff(L - j - 1, L - 1 - i, r);
	ull a = i, b = L - 1 - j;
	ull corr = power(max(a,b) - min(a,b));
	if(a > b) {
		return diffB*corr == diffA;	
	}
	else {
		return diffB == diffA*corr;
	}
}

int f(int len) {
	ull &aux = pd[len];
	if(aux != -1) return aux;
	aux = 0;
	if(len == 0) return aux = 0;
	if(pal(0, len - 1)) {
		return aux = 1 + f(len / 2);
	} else {
		return aux = 0;
	}
}


int main() {
	scanf(" %s", str);
	L = strlen(str);
	for(int i = 0; i < L; i++) {
		pd[i + 1] = pd2[i] = -1;
	}
	ull base = 1;
	h[0] = val(str[0]);
	for(int i = 1; i < L; i++) {
		base *= BASE;
		h[i] = h[i - 1] + base*val(str[i]);
	}
	r[0] = val(str[L - 1]);
	base = 1;
	for(int i = 1; i < L; i++) {
		base *= BASE;
		r[i] = r[i - 1] + base*val(str[L - i - 1]);
	}
	int ans = 0;
	for(int i = 0; i < L; i++) {
		ans += f(i + 1);
	}
	printf("%d\n", ans);
	return 0;
}
