import java.io.*;
import java.util.*;
public class Main{
	public static void main(String args[]) throws Exception {
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int m=cin.nextInt();
		int q=cin.nextInt();
		int A[][] = new int[201][201];
		int B[][] = new int[201][201];
		int C[][] = new int[201][201];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				A[i][j]= cin.nextInt();
		for(int i=1;i<=m;i++)
			for(int j=1;j<=q;j++)
				B[i][j]= cin.nextInt();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=q;j++){
				C[i][j]=0;
				for(int k=1;k<=m;k++)
					C[i][j]+=A[i][k]*B[k][j];
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=q;j++) {
				System.out.print(C[i][j]);
				System.out.print('\t');
			}
			System.out.print('\n');
		}
	}
}
