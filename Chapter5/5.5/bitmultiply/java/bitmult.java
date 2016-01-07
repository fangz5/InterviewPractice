import java.util.Scanner;

public class bitmult {
    public static int multiply(int x, int y) {
	int sum = 0;
 	while (y != 0) {
	    if ( (y&1) != 0 ) {
		sum = add(sum, x);
	    }
	    x <<= 1; y >>>= 1;
	}
	return sum;
    }

    public static int add(int x, int y) {
	int sum = 0, mask = 1, xBit = 0, yBit = 0, carry = 0;
	while ( (x != 0) || (y != 0) ) {
	    xBit = x&mask; yBit = y&mask;
	    sum = sum | (xBit^yBit^carry);
	    carry = (xBit&yBit) | (yBit&carry) | (carry&xBit);
	    carry <<= 1;
   	    x &= ~mask;
	    y &= ~mask;
	    mask <<= 1;
	}
	return sum | carry;
    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int x = in.nextInt(), y = in.nextInt();
	System.out.println("Product:"+multiply(x,y));
    }
}