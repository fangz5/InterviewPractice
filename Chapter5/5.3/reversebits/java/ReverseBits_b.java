import mypackage.ReverseBits;

public class ReverseBits_b {
    ReverseBits_b() {
	InitializeTable();
    }
    private static final int TABLE_SIZE = 65536;
    private static long lReverseTable[] = new long[TABLE_SIZE];
    private static void InitializeTable() {
	for (int i=0; i<TABLE_SIZE; i++) {
	    lReverseTable[i] = mypackage.ReverseBits.ReverseBits((long)i)>>>48;
	    if (i%10000 == 0) {
		System.out.println(Integer.toBinaryString(i) + ":"
				   + Long.toBinaryString(lReverseTable[i]));
	    }
	}
    };
    
    private static long ReverseBits_b(long x) {
	long nWordMask = 0xFFFF;
	return lReverseTable[(int)(x & nWordMask)] << 48 |
	    lReverseTable[(int)(x>>16 & nWordMask)] << 32 |
	    lReverseTable[(int)(x>>32 & nWordMask)] << 16 |
	    lReverseTable[(int)(x>>48 & nWordMask)];
    }
    
    public static void main(String[] args) {
	//       	InitializeTable();
	ReverseBits_b obj = new ReverseBits_b();
	long x = 0xF01F;
	System.out.println("Bf:" + Long.toBinaryString(x));
	System.out.println("Af:" + Long.toBinaryString(obj.ReverseBits_b(x)));
    }
}
