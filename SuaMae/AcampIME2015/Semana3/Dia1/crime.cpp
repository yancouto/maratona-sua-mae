#include <bits/stdc++.h>

using namespace std;

const int N = 10007;

pair<int, int> chn[N];
pair<int, int> acc[N];
int ini, fim, mini, maxi, last, pss, a,b;
int ss, n;

int main () {
	while (scanf("%d %d", &ini, &fim) != EOF) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			chn[2*i].first = a;
			chn[2*i].second = 1;
			chn[2*i+1].first = b+1;
			chn[2*i+1].second = -1;
		}

		sort(chn, chn+2*n);

		ss = 0;
		acc[0].first = chn[0].first;
		acc[0].second = chn[0].second;
		for (int i = 1; i < 2*n; i++) {
			if (acc[ss].first == chn[i].first)
				acc[ss].second += chn[i].second;
			else {
				acc[++ss].first = chn[i].first;
				acc[ss].second = chn[i].second;
			}
		}
		ss++;

		pss = acc[0].second;
		last = acc[0].first;

		maxi = 0;
		mini = INT_MAX;

		for (int i = 1; i < ss; i++) {
			if ((last <= ini && ini < acc[i].first) || (last <= fim && fim <= acc[i].first) || (last <= fim && ini <= acc[i].first)) {
				mini = min(mini, pss);
				maxi = max(maxi, pss);
			}

			pss += acc[i].second;
			last = acc[i].first;
		}

		if (last <= fim) {
			mini = min(mini, pss);
			maxi = max(maxi, pss);
		}
		
		if (mini == INT_MAX)
			printf("0 0\n");
		else
			printf("%d %d\n", mini, maxi);
	}
}
