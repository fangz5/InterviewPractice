import java.util.Scanner;

public class palin {
    public static boolean isPalin(int x){
	if (x<0) return false;
	if (x==0) return true;
	int denom = (int)Math.pow(10,(int)(Math.log10(x)));
	while (x>9) {
	    if (x/denom != x%10) return false;
	    x %= denom;
	    x /= 10;
	    denom /= 100;
	}
	return true;
    }

    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int x = in.nextInt();
	if (isPalin(x)){
	    System.out.println("true");
	}else System.out.println("false");
    }
}