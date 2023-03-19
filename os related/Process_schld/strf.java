package Process_schld;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class strf {
	
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public strf() throws IOException
	{
		int n,i,j,time=0,tt=0,k,min,flag,j1=0,cnt=0;
		System.out.println("enter the number of process");
		n=Integer.parseInt(br.readLine());
		int[] arr=new int[n];
		int[] exe=new int[n];
		int[] cp=new int[n];
		System.out.println("enter the arrival time and execution of processes");
		for(i=0;i<n;i++)
		{
			System.out.println("arrival time of process "+i);
			arr[i]=Integer.parseInt(br.readLine());
			System.out.println("execution time of process "+i);
			exe[i]=Integer.parseInt(br.readLine());
			tt+=exe[i];
			cp[i]=0;
		}
		min=exe[0];
		k=0;
		System.out.print("p"+(k+1)+" : 0 to ");
		for(i=1;i<=tt;i++)
		{
			flag=0;
			for(j=0;j<n;j++)
			{
				if(k==j)
					continue;
				else
				{
					if(arr[j]<=i&&exe[j]<min)
					{
						min=exe[j];
						flag=1;
						j1=j;
					}
				}
			}
			if(flag==0)
			{
				if(exe[k]==0)
				{
					if(cp[k]!=1)
					{
						cp[k]=1;
						cnt++;
					}
					continue;
				}
				else
				{
					exe[k]--;
				}
			}
			else
			{
				System.out.println(i);
				System.out.print("p"+(k+1)+" : "+i+" to ");
				k=j1;
			}
			if(cnt==n)
				{
				System.out.println(i);
				break;
				}
				
		}
		
	}
	public static void main(String[] args) throws IOException
	{
		new strf();
	}

}
