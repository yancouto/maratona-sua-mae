#include <cstdio>
#include <algorithm>

using namespace std;

struct team {
	int k, dA, dB;
};

team teams[10005];

inline int sortB(const team& a, const team& b) {
	if (a.dB == b.dB) return a.dA < b.dA;
	return a.dB < b.dB;
}

inline int sortA(const team& a, const team& b) {
	if (a.dA == b.dA) return a.dB < b.dB;
	return a.dA < b.dA;
}

int main() {
	int n, A, B;

	while (1) {
		scanf("%d %d %d", &n, &A, &B);
		if (!A && !B && !n) return 0;
		for (int i=0;i<n;++i)
			scanf("%d %d %d", &teams[i].k, &teams[i].dA, &teams[i].dB);
		sort(teams, teams + n, sortA);
		int tA = A, tB = B;
		long long int d = 0;
		for (int i=0;i<n;++i) {
			team& t = teams[i];
			if (t.dA <= t.dB) {
				long long int p = min(t.k, tA);
				d += p*t.dA;
				tA -= p;
				if (p < t.k) {
					tB -= t.k-p;
					d += (t.k-p)*t.dB;
				}
			} else {
				long long int p = min(t.k, tB);
				d += p*t.dB;
				tB -= p;
				if (p < t.k) {
					tA -= t.k-p;
					d += (t.k-p)*t.dA;
				}
			}
		}
		tA = A, tB = B;
		long long _d = 0;
		sort(teams, teams + n, sortB);
		for (int i=0;i<n;++i) {
			team& t = teams[i];
			if (t.dB <= t.dA) {
				long long int p = min(t.k, tB);
				_d += p*t.dB;
				tB -= p;
				if (p < t.k) {
					tA -= t.k-p;
					_d += (t.k-p)*t.dA;
				}
			} else {
				long long int p = min(t.k, tA);
				_d += p*t.dA;
				tA -= p;
				if (p < t.k) {
					tB -= t.k-p;
					_d += (t.k-p)*t.dB;
				}
			}
		}
		printf("%llu\n", min(d, _d));
	}

	return 0;
}