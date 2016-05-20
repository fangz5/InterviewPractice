import java.util.*;

class Result{
    Integer begin;
    Integer end;
    Integer sum;
    Result(){
	begin = 0;
	end = -1;
	sum = 0;
    }
}

public class MaxSubArray{
    public static Result findMaxSubArray(ArrayList<Integer> A){
	Result result = new Result();
	Result tmpResult =  new Result();
	
	//Keep record of largest sum
	for (Integer i = 0; i < A.size(); i++) {
	    //If new sum greater than largest sum, update largest sum
	    tmpResult.end = i;
	    tmpResult.sum += A.get(i);
	    if (tmpResult.sum > result.sum){
		result.begin = tmpResult.begin;
		result.end = tmpResult.end;
		result.sum = tmpResult.sum;
	    } else if (tmpResult.sum <= 0) {
	    //If new sum less than or equal to 0, reset tmpResult
		tmpResult.begin = i + 1;
		tmpResult.end = i;
		tmpResult.sum = 0;
	    }
	}
	return result;
    }
    public static void main(String[] args){
	ArrayList<Integer> A = new ArrayList<Integer>(
	    Arrays.asList(2,3,-1,-2,4,-10,-3,5,3));
	Result result = findMaxSubArray(A);
	System.out.println(result.begin+" "+result.end+" "+result.sum);
    }
}
