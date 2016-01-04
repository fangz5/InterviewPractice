public class parity {
    static public short parity(long x) {
	x ^= x>>32;
	x ^= x>>16;
	x ^= x>>8;
	x ^= x>>4;
	x ^= x>>2;
	x ^= x>>1;
	return (short)(x&1);
    }

    public static void main(String[] args) {
	long x = 0xFF000001;
	System.out.println("Type long has " + Long.SIZE + " bits.");
	System.out.println(Long.toBinaryString(x) + " has parity " + parity(x));
    }
}
