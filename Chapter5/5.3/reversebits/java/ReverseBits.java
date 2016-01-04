package mypackage;

public class ReverseBits {
    public static long SwapBits(long x, int i, int j) {
	long mask_i = 1L<<i;
	long mask_j = 1L<<j;
	if ( (x & mask_i) != (x & mask_j) ) {
	    x ^= mask_i^mask_j;
	}
	return x;
    }

    public static long ReverseBits(long x) {
	for (int i=0; i<32; i++) {
	    x = SwapBits(x,i,63-i);
	}
	return x;
    }

    public static void main(String[] args) {
	long x = 0xF01F;
	System.out.println("Bf:" + Long.toBinaryString(x));
	System.out.println("Af:" + Long.toBinaryString(ReverseBits(x)));
    }
}
