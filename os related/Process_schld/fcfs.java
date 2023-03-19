package Process_schld;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class fcfs {
	
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public fcfs() throws  IOException
	{
		int n,i,j,time=0;
		System.out.println("enter the number of process");
		n=Integer.parseInt(br.readLine());
		int[] arr=new int[n];
		int[] exe=new int[n];
		System.out.println("enter the arrival time and execution of processes");
		for(i=0;i<n;i++)
		{
			System.out.println("arrival time of process "+i);
			arr[i]=Integer.parseInt(br.readLine());
			System.out.println("execution time of process "+i);
			exe[i]=Integer.parseInt(br.readLine());
		}
		for(i=0;i<n;i++)
		{
			System.out.println("process "+i+" start time "+time+" end time "+(time+exe[i]));
			time=time+exe[i];
			
		}
		
	}
	public static void main(String[] args) throws IOException
	{
		new fcfs();
	}

}
