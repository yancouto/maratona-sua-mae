import java.util.*;
import java.io.*;
import java.math.*;

public class C {
	static BigInteger[][] memo;
	static boolean[][] seen;
	public static BigInteger solve(int l, int open) {
		if(l == 0) return BigInteger.ONE;
		if(seen[l][open]) return memo[l][open];
		seen[l][open] = true;
		BigInteger sol = solve(l - 1, open + 1);
		if(open > 0) sol = sol.add(solve(l, open - 1));
		memo[l][open] = sol;
		return sol;
	}

	public static void main(String[] args) throws Exception {
		memo = new BigInteger[62][62];
		seen = new boolean[62][62];
		for(int i = 0; i < 62; i++)
			for(int j = 0; j < 62; j++)
				seen[i][j] = false;
		Scanner in = new Scanner(new BufferedReader(new FileReader("catalonian.in")));
		PrintStream out = new PrintStream(new File("catalonian.out"));
		while(true) {
			int x = in.nextInt();
			if(x == 0) return;
			out.println(solve(x, 0));			
		}
	}
}
