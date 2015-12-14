#include <bits/stdc++.h>

using namespace std;

const int N = 29;


int getCard(char a) {
	if (a >= '2' && a <= '9')
		return a - '2';
	else if (a=='T')
		return 8;
	else if (a=='J')
		return 9;
	else if (a=='Q')
		return 10;
	else if (a=='K')
		return 11;
	else
		return 12;
}

int getSuite (char a) {
	if (a == 'H')
		return 4;
	else if (a == 'S')
		return 3;
	else if (a == 'D')
		return 2;
	else
		return 1;
}

pair<int, int> ac[N];
int res, n;
char a, b;
pair<int, int> aux;
set<pair<int, int> >::iterator it;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		set<pair<int, int> > s;

		res = 0;
		for (int i = 0; i < n; i++){
			scanf(" %c %c", &a, &b);
			ac[i].first = getCard(a);
			ac[i].second = getSuite(b);
		}

		for (int i = 0; i < n; i++) {
			scanf(" %c %c", &a, &b);
			aux.first = getCard(a);
			aux.second = getSuite(b);
			s.insert(aux);
		}

		for (int i = 0; i < n; i++) {
			it = s.upper_bound(ac[i]);
			if (it != s.end()) {
				s.erase(it);
				res++;
			} else {
				s.erase(s.begin());
			}
		}

		printf("%d\n", res);
	}
}
