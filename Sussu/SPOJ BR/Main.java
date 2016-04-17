import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	boolean dr = true;
	BigInteger d = new BigInteger("0");
	int d2 =0;
	BigInteger adding = new BigInteger("1");
	public static void main(String[]args)throws java.lang.Exception{
		Scanner in = new Scanner(System.in);
		Main krav = new Main();
		while(krav.dr==true){
			int num= in.nextInt(); 
			BigInteger num2= in.nextBigInteger();
			if(num!=0){
				BigInteger[] itens = new BigInteger[num];
				for(int i=0; i<num; i++){
					BigInteger preco=in.nextBigInteger();
					itens[i] = preco;
				}
				krav.d = krav.d .add(krav.adding);
				krav.d2++;
				BigInteger soma=new BigInteger("0");
				for (int r=0; r<num; r++){
					soma= soma.add(itens[r]);
				}
				BigInteger repart = soma.divide(num2);
				System.out.println("Bill #"+ krav.d + " costs " + soma + ": each friend should pay " + repart+"\n");
			}else{
				System.exit(0);
			}
		}in.close();
	}
} 