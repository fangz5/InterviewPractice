import java.util.Scanner;

public class reverse {
    public static int reverseDigit(int x){
	int sign = 1;
	if (x<0) sign = -1;
	x *= sign;
	
	int result=0;
	while (x>0) {
	    result *= 10;
	    result += x%10;
	    x /= 10;
	}

	return result*sign;
    }

    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int x=in.nextInt();
	System.out.println("reverse:"+reverseDigit(x));
    }
}