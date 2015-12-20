import java.util.Scanner;

public class OneBits_d {
    static public int numOneBits(int n) {
      int numOnes = 0;
      while (n != 0) {
	  numOnes++;
	  n = n & (n-1);
      }
      return numOnes;
    }

    public static void main(String[] args) {
      System.out.print("Input an integer:");
      Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      System.out.println(n + " in binary is " + Integer.toBinaryString(n));
      System.out.println(n + " has " + numOneBits(n) + " bits set to 1.");
    }
}
