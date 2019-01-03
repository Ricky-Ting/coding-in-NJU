import java.io.*;
import java.util.*;
public class Main {
	
	public static void main(String args[]) throws Exception {
		Scanner cin = new Scanner(System.in);
		int n=cin.nextInt();
		int m=cin.nextInt();
		People[] p = new People[1000];
		for(int i=0;i<n;i++){
			String name=cin.next();
			int age=cin.nextInt();
			p[i]=new People(name,age);
		}
		for(int i=0;i<n;i++){
			p[i].print();
		}
		for(int i=1;i<=m;i++){
			int a=cin.nextInt();
			int b=cin.nextInt();
			System.out.println(p[a].equals(p[b]));
		}

	}
}
class People {
		protected String name;
		protected int age;
		public People (String name,int age) {
			this.name=name;
			this.age=age;
		}
		public void print() {
			System.out.println("Name="+name+" Age="+age);
		}
		public boolean equals(Object o){
			People A= (People)o;
			if( name.equals(A.name)&& (A.age==age))
				return true;
			return false;

		}
	
	}



