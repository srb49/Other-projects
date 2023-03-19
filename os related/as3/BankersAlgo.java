package as3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BankersAlgo {

	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public BankersAlgo() throws  IOException
	{
		int noPro=0,noRes=0,flag,i,j,k=0;
		System.out.println("enter number of processes");
		noPro=Integer.parseInt(br.readLine());
		System.out.println("enter number of resources");
		noRes=Integer.parseInt(br.readLine());
		
		int[][] allo=new int[noPro][noRes];
		int[][] mneed=new int[noPro][noRes];
		int[][] fneed=new int[noPro][noRes];
		
		int[] ss=new int[noPro];//safe sequence
		int[] flagArr=new int[noPro];
		
		int[] avl=new int[noRes];
		
		System.out.println("enter allocated resources against each process");
		for(i=0;i<noPro;i++)
		{
			for(j=0;j<noRes;j++)
			{
				System.out.println("for process P"+(i+1)+" -> resources R"+(j+1)+" =");
				allo[i][j]=Integer.parseInt(br.readLine());
			}
		}
		
		System.out.println("enter maximum need of each process");
		for(i=0;i<noPro;i++)
		{
			for(j=0;j<noRes;j++)
			{
				System.out.println("for process P"+(i+1)+" -> resources R"+(j+1)+" =");
				mneed[i][j]=Integer.parseInt(br.readLine());
			}
		}
		
		//future need
		for(i=0;i<noPro;i++)
		{
			for(j=0;j<noRes;j++)
			{
				fneed[i][j]=mneed[i][j]-allo[i][j];
			}
		}
		System.out.println("enter available resources");
		for(j=0;j<noRes;j++)
		{
			System.out.println("availibility of resource R"+(j+1));
			avl[j]=Integer.parseInt(br.readLine());
		}
		for(j=0;j<noPro;j++)
		{
			flagArr[j]=0;
		}
		for(i=0;i<noPro;i++)
		{
			flag=0;
			int res=0;
			if(flagArr[i]==0)
				for(j=0;j<noRes;j++)
				{
				if(fneed[i][j]<=avl[j])
					res++;					
				}
			
			if(noRes==res)
			{
				flagArr[i]=1;
				for(j=0;j<noRes;j++)
				{
					avl[j]+=allo[i][j];
					
				}
				ss[k]=i+1;
				k++;
				flag=1;
			}
			
			if(flag==1&&i==noPro)
				i=0;
			else if(flag==0&&i==noPro)
				break;
			System.out.println("safe sequence is");
			for(i=0;i<k;i++)
			{
				System.out.println("P"+(i+1));
			}
			System.out.println("processes under deadlock");
			for(i=0;i<noPro;i++)
			{
				if(flagArr[i]==0)
					System.out.println("P"+(i+1));
			}
		}
		
	}
	public static void main(String[] args) throws IOException
	{
		new BankersAlgo();
	}
}
