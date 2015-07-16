#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 110, MAXK = 2000, ALF = 'z' - 'a' + 1, INF = 1 << 30;

int bit[MAXL*MAXK][ALF], sum[MAXL*MAXK][ALF], mrk[MAXL*MAXK], lim;

int read(int c, int idx) {
	int sum = 0;
	for(int i = idx; i > 0; i -= i & -i) sum += bit[i][c];
		return sum;
}

void update(int c, int idx) {
	for(int i = idx; i <= lim; i += i & -i) bit[i][c]--;
}

int bb(int ini, int fim, int ch, int val) {
		if(ini > fim) return INF;
		int mid = (ini + fim) / 2;
		int aux = read(ch, mid);
		if(sum[mid][ch] + aux == val) return min(bb(ini, mid - 1, ch, val), mid);
		else if(sum[mid][ch] + aux < val) return bb(mid + 1, fim, ch, val);
		else return bb(ini, mid - 1, ch, val);
}

int main(){
	int k;
	char str[MAXL];
	scanf("%d %s", &k, str);
	int len = strlen(str);
	lim = len*k;
	for(int i = 1; i <= lim; i++) {
		for(int j = 0; j < ALF; j++) {
			sum[i][j] = sum[i-1][j] + (str[(i-1) % len] - 'a' == j);
		}
		mrk[i] = 1;
	}
	int n;
	scanf("%d", &n);
	while(n--) {
		int p; char ch;
		scanf("%d %c", &p, &ch);
		int pos = bb(1, lim, ch - 'a', p);
		mrk[pos] = 0;
		update(ch - 'a', pos);
	}
	for(int i = 1; i <= lim; i++) {
		if(mrk[i]) {
			printf("%c", str[(i - 1) % len]);
		}
	}
	printf("\n");
	return 0;
}