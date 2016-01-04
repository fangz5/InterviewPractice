public class SwapBits {
    static public long SwapBits(long x, int i, int j) {
	long mask_i = 1L<<i;
	long mask_j = 1L<<j;
	if ( (x & mask_i) != (x & mask_j) ) {
	    x ^= mask_i^mask_j;
	}
	return x;
    }

    public static void main(String[] args) {
	long x = 0xFFF1;
	int i=2;
	int j=10;
	System.out.println("Bf:" + Long.toBinaryString(x));
	System.out.println("Af:" + Long.toBinaryString(SwapBits(x,i,j)));
    }
}
