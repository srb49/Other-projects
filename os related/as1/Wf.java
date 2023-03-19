/*worst fit*/
package as1;

import java.io.*;
import java.util.Random;

public class Wf 
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public Wf() throws IOException
	{
		int n=0,i,jmin=1000,jmax=0;//here we assume that minimum job size will be less than 1000
		System.out.println("enter the number of jobs");
		n=Integer.parseInt(br.readLine());
		if(n>5)
		{
			System.out.println("1st 5 jobs will be allocated");
		n=5;
		}
		int[] job=new int[n];
		int[] hole=new int[5];
		
		System.out.println("enter job size one by one");
		for(i=0;i<n;i++)
		{
			System.out.println("enter size of job "+(i+1));
			job[i]=Integer.parseInt(br.readLine());
			if(job[i]>jmax)
				jmax=job[i];
			if(job[i]<jmin)
				jmin=job[i];
		}
		
		Random rand=new Random();//this is for creating hole sizes randomly 
		
		for(i=0;i<5;i++)
		{
			int sz=rand.nextInt(2*jmax-jmin);
			hole[i]=sz;
		}
		for(i=0;i<5;i++)
		{
			System.out.print(" hole "+(i+1)+" has size "+hole[i]);
			if(i+1<=n)
				System.out.print("\t job "+(i+1)+" has size "+job[i]);
			
			System.out.println();
		}
		
		System.out.println();
		System.out.println("allocated jobs and remaining places");
		
		for(i=0;i<n;i++)
		{
			int bestHole=hole[0],k=0;
			for(int j=0;j<5;j++)
			{
				if(job[i]<=hole[j])
				{
					if(bestHole<hole[j])
					{
					bestHole=hole[j];
					k=j;
					}
				
				}
				
			}
			System.out.println();
			System.out.print("job "+(i+1)+" is allocated to hole "+(k+1));
			hole[k]=hole[k]-job[i];
			System.out.print("\t remaining place in hole "+(k+1)+" is "+hole[k]);
		}
		
		
		
	}
	public static void main(String[] args)throws IOException
	{
		new Wf();
	}
}
