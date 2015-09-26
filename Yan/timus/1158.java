import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class t1158 {
	static int n, m;
	static int[] f, pr, ba;
	static int[][] tr;

	static BigInteger[][] memo;
	static int[][] seen;
	static BigInteger solve(int i, int v) {
		if(ba[v] != 0) return BigInteger.ZERO;
		if(i == m) return BigInteger.ONE;
		if(seen[i][v] != 0) return memo[i][v];
		seen[i][v] = 1;
		BigInteger r = BigInteger.ZERO;
		for(int w = 0; w < n; w++) {
			int p = v;
			while(p != 0 && tr[p][w] == 0) p = pr[p];
			p = tr[p][w];
			r = r.add(solve(i + 1, p));
		}
		memo[i][v] = r;
		return r;
	}


	public static void main(String[] args) {
		f = new int[100000];
		pr = new int[150];
		ba = new int[150];
		tr = new int[150][50];
		Scanner in = new Scanner(System.in);
		n = in.nextInt(); m = in.nextInt(); int p = in.nextInt();
		String s = in.next();
		int i, j;
		for(i = 0; i < n; i++)
			f[s.charAt(i) + 256] = i;
		int tn = 0;
		for(i = 0; i < p; i++) {
			s = in.next();
			int v = 0;
			for(j = 0; j < s.length(); j++) {
				if(tr[v][f[s.charAt(j) + 256]] == 0)
					tr[v][f[s.charAt(j) + 256]] = ++tn;
				v = tr[v][f[s.charAt(j) + 256]];
			}
			ba[v] = 1;
		}
		Queue<Integer> q = new LinkedList<Integer>();
		for(i = 0; i < n; i++)
			if(tr[0][i] != 0) {
				q.add(tr[0][i]);
				pr[tr[i][0]] = 0;
			}
		while(q.size() > 0) {
			int x = q.poll();
			for(i = 0; i < n; i++) {
				if(tr[x][i] == 0) continue;
				p = pr[x];
				while(p != 0 && tr[p][i] == 0) p = pr[p];
				p = tr[p][i];
				pr[tr[x][i]] = p;
				if(ba[p] != 0) ba[tr[x][i]] = 1;
				q.add(tr[x][i]);
			}
		}
		memo = new BigInteger[54][150];
		seen = new int[54][150];
		System.out.println(solve(0, 0));
	}
}
