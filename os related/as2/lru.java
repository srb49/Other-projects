package as2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class lru {

	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public void show(int page[])
	{
		for(int i=0;i<4;i++)
			System.out.print("\t"+page[i]);
		System.out.println();
	}
	public lru() throws  IOException
	{
		int n,i,j,hit=0,mis=4,lrucnt,lrumin;
		System.out.println("enter the no of processes");
		n=Integer.parseInt(br.readLine());
		int[] page =new int[4];
		int[] lru=new int[4];
		int[] proc=new int[n];
		for(i=0;i<n;i++)
		{
			System.out.println("entre the processes");
			proc[i]=Integer.parseInt(br.readLine());
		}
		//1st initialization
		page[0]=proc[0];
		page[1]=proc[1];
		page[2]=proc[2];
		page[3]=proc[3];
		
		show(page);
		lru[0]=0;lru[1]=1;lru[2]=2;lru[3]=3;
		lrucnt=3;
		lrumin=0;
		for(i=4;i<n;i++)
		{
			int flag=0;
			for(j=0;j<4;j++)
			{
				if(page[j]==proc[i])
				{
				hit++; 
				//System.out.println("it is a hit for process "+proc[i]);
				flag=1;
				lrucnt++;
				lru[j]=lrucnt;
				break;
				}
			}
			if(flag==0)
			{
				mis++;
				int lindex=0;
				lrumin=lru[0];
				for(j=0;j<4;j++)
				{
					if(lrumin>lru[j])
					{
						lrumin=lru[j];
						lindex=j;
					}	
				}
				page[lindex]=proc[i];
				lrucnt++;
				lru[lindex]=lrucnt;
			}
			for(j=0;j<4;j++)
				System.out.print("\t"+page[j]);
			System.out.println();
		}
		System.out.println("number of hit "+hit);
		System.out.println("number of miss "+mis);
		
		
	}
public static void main(String[] args) throws IOException
	{
	new lru();
	}
}
