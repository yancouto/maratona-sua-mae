import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	static void mult(BigInteger[][] a, BigInteger[][] b, BigInteger[][] c) {
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) {
				c[i][j] = BigInteger.ZERO;
				for(int k = 0; k < 2; k++)
					c[i][j] = c[i][j].add(a[i][k].multiply(b[k][j]));
			}
	}

	static void cp(BigInteger[][] a, BigInteger[][] b) {
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				b[i][j] = a[i][j];
	}


	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		while(true) {
			BigInteger resp[][] = new BigInteger[2][2];
			BigInteger a[][] = new BigInteger[2][2];
			BigInteger b[][] = new BigInteger[2][2];
			resp[0][0] = resp[1][1] = a[0][0] = a[0][1] = a[1][0] = BigInteger.ONE;
			resp[1][0] = resp[0][1] = a[1][1] = BigInteger.ZERO;
			int x = in.nextInt();
			int n = in.nextInt();
			if(n == 0 && x == 0) return;
			for(int i = 1; i <= n; i <<= 1) {
				if((i & n) != 0) {
					mult(a, resp, b);
					cp(b, resp);
				}
				mult(a, a, b);
				cp(b, a);
			}
			System.out.println(BigInteger.valueOf(x).multiply(resp[0][0].add(resp[1][0])));
		}
	}

}
