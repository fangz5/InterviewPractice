import java.util.Scanner;

public class power{
    public static int pow(int x, int y){
	int result = 1;
	int weight = x;
	while (y != 0) {
	    if ((y&1)==1) result *= weight;
	    weight *= weight;
	    y >>= 1;
	}
	return result;
    }

    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int x=in.nextInt(), y=in.nextInt();
	if ((x<0) || (y<0)) return;
	System.out.println("x^y:"+pow(x,y));
    }
}