import java.util.*;

public class Celebrity{
	public static void main(String argv[]){
		int[][] matrix = {
			{1, 1, 1, 1},
			{1, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 1}
		};
		PrintMatrix(matrix);
		System.out.println(FindCelebrity(matrix));
	}
	static int FindCelebrity(int[][] matrix){
		int i = 0, j = 1;
		while (j < matrix.length){
			if (matrix[i][j] == 0) {
				j++;
			} else {
				i = j++;
			}
		}
		return i;
	}
	static void PrintMatrix(int[][] matrix){
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				System.out.print(matrix[i][j]+" ");
			}
			System.out.println();
		}
	}
}