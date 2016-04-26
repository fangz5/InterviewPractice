import java.util.Scanner;

public class division{
    public static int firstBitPos(int x) {
	if (x<1) return -1;
	int result = 0;
	while ( x != 1){
	    x >>= 1;
	    result++;
	}
	return result;
    }

    public static int div(int x, int y){
	if (x<y) return 0;
	int result = 0;
	int power = firstBitPos(x)-firstBitPos(y);
	while (x>=y) {
	    int denominator = (y<<power);
	    if (x>=denominator) {
		result += (1 << power);
		x -= denominator;
	    }
	    power--;
	}
	return result;
    }

    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int x = in.nextInt();
	int y=in.nextInt();
	if ( (x<0)||(y<=0) ) return; 
	System.out.println(div(x,y));
    }
}