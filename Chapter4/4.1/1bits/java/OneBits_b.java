import java.util.Scanner;

public class OneBits_b {
    static public int numOneBits(int n) {
      int numOnes = 0;
      for (int i = 0; i < Integer.SIZE; i++) {
	  int m = 1 << i;
	  if ((n & m) == m) {
	      numOnes++;
	  }
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
