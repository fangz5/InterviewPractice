import java.util.*;

public class MaxSubArray2{
    public static Integer begin = 0;
    public static Integer end = 0;

    public static void findMaxSubArray(ArrayList<Integer> A){
	Integer maxSum = 0;
	Integer minSum = 0;
	Integer sum = 0;
	Integer minIndex = -1;
	for (int i = 0; i < A.size(); i++){
	    sum += A.get(i);
	    if (sum < minSum){
		minSum = sum;
		minIndex = i;
	    }else if (sum - minSum > maxSum){
		maxSum = sum - minSum;
		begin = minIndex + 1;
		end = i;
	    }
	}
    }
    
    public static void main(String[] args){
	ArrayList<Integer> A = new ArrayList<Integer>(
	    Arrays.asList(2,3,-1,-2,4,-10,-3,5,0));
	findMaxSubArray(A);
	System.out.println(begin+" "+end);
    }
}
