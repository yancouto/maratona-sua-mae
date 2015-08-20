namespace f {
	const int maxv = 100009;
	const int maxe = 300009 * 2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s;
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	int us[maxv], te, cr[maxv];
	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		if(us[u] == te) return 0;
		us[u] = te;
		for(int &i = cr[u]; i != -1; i = nx[i]) {
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1) {
				if(int a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
			}
		}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t)) {
			te++;
			for(int i = 0; i < n; i++) cr[i] = es[i];
			while(a = dfs(s, t, inf))
				fl += a, te++;
		}
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow(int m=maxe/2) { memset(fl, 0, sizeof(num) * m*2); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}
