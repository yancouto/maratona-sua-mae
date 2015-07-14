#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100, INF = 1 << 29;

int n, v[MAX], u[MAX*MAX*MAX], l = 0;

inline int lb(int ini, int fim, int val) {
	if(ini > fim) return INF;
	int mid = (ini + fim) / 2;
	if(u[mid] == val) return min(mid, lb(ini, mid - 1, val));
	else if(u[mid] < val) return lb(mid + 1, fim, val);
	else return lb(ini, mid - 1, val);
}

inline int ub(int ini, int fim, int val) {
	if(ini > fim) return -INF;
	int mid = (ini + fim) / 2;
	if(u[mid] == val) return max(mid, ub(mid + 1, fim, val));
	else if(u[mid] < val) return ub(mid + 1, fim, val);
	else return ub(ini, mid - 1, val);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				u[l++] = v[i]*v[j] + v[k];
			}
		}
	}
	sort(u, u + l);
	long long ans = 0;	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(v[i] == 0) continue;
				int aux = ub(0, l - 1, (v[j] + v[k])*v[i]);
				if(aux == -INF) continue;
				ans +=  aux - lb(0, l - 1, (v[j] + v[k])*v[i]) + 1;
			}
		}
	}	
	printf("%lld\n", ans);
	return 0;
}
