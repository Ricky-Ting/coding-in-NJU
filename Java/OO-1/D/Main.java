import java.io.*;
import java.util.*;
public class Main{
	public static void main(String args[]) throws Exception {
		Scanner cin= new Scanner(System.in);
		String time = cin.next();
		MyTime clock = new MyTime(time);
		String op= cin.next();
		while(!op.equals("E"))
		{
			if(op.equals("ADDH"))
			{
				int t=cin.nextInt();
				clock.addh(t);
			}
			if(op.equals("ADDM"))
			{
				int t=cin.nextInt();
				clock.addm(t);
			}
			if(op.equals("ADDS"))
			{
				int t=cin.nextInt();
				clock.adds(t);
			}
			if(op.equals("SUBH"))
			{
				int t=cin.nextInt();
				clock.subh(t);
			}
			if(op.equals("SUBM"))
			{
				int t=cin.nextInt();
				clock.subm(t);
			}
			if(op.equals("SUBS"))
			{
				int t=cin.nextInt();
				clock.subs(t);
			}
			if(op.equals("P"))
			{
				clock.display();
			}
			op=cin.next();

		}
	
	}


}

class MyTime{
	private int hour;
	private int minute;
	private int second;
	

	public MyTime (String time)
	{
		String Hour=time.substring(0,2);
		String Min=time.substring(3,5);
		String Sec=time.substring(6,8);
		hour=Integer.parseInt(Hour);
		minute=Integer.parseInt(Min);
		second=Integer.parseInt(Sec);
	}


	public void addh(int a)
	{
		hour+=a;
	}
	public void addm(int a)
	{
		minute+=a;
	}
	
	public void adds(int a)
	{
		second+=a;
	}

	public void subh(int a)
	{
		hour-=a;
	}

	public void subm(int a)
	{
		minute-=a;
	}
	
	public void subs(int a)
	{
		second-=a;
	}
	
	public void display()
	{
		while(second<0)
		{
			second+=60;
			minute--;
		}
		while(second>=60)
		{
			second-=60;
			minute++;
		}
		while(minute<0)
		{
			minute+=60;
			hour--;
		}
		while(minute>=60)
		{
			minute-=60;
			hour++;
		}
		while(hour<0)
			hour+=24;
		while(hour>=24)
			hour-=24;
		String h= String.format("%02d",hour);
		String m= String.format("%02d",minute);
		String s= String.format("%02d",second);
		System.out.println(h+':'+m+':'+s);
	}



}
