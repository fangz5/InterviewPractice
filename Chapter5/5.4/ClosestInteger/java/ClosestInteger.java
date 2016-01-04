import java.util.Scanner;

public class ClosestInteger {
    public static int ClosestInteger(int x) {
	if ((x==0)||(~x==0)) {
	    throw new IllegalArgumentException("All bits are 0 or 1.");
	}
	return x^(x&~(x-1))^(~x&~(~x-1));
    }

    public static void main(String[] args) {
	try {
	    System.out.print("Input an integer:");
	    Scanner in = new Scanner(System.in);
	    int x = in.nextInt();
	    System.out.println("bf:"+Integer.toBinaryString(x));
	    System.out.println("af:"+Integer.toBinaryString(ClosestInteger(x)));
	} catch (Exception e) {
	    System.out.println(e.getMessage());
	}
    }
}
