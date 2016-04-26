import java.util.Scanner;
import java.util.Random;

public class random{
    public static int oneBitRand(){
	Random rand = new Random();
	return rand.nextInt(2);
    }

    public static int myRand(int a, int b){
	int range = b - a;
	int result = 0;
	do {
	    result = 0;
	    for (int i=0; i<(Math.log(range+1)/Math.log(2))+1; i++) {
		result <<= 1;
		result += oneBitRand();
	    }	    
	} while (result > range);
	return result + a;
    }

    public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	while (true) {
	    int a = in.nextInt(), b = in.nextInt(), loops = in.nextInt();
	    if (a==b) return;
	    
	    int array[] = new int[b-a+1];
	    
	    for (int i = 0; i<loops; i++) array[myRand(a,b)-a]++;
	    for (int i = 0; i<=b-a; i++){
		System.out.print((i+a)+":"+array[i]+"|");
	    }
	    System.out.print("\n");
	}
    }
}