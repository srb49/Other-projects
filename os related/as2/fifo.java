package as2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class fifo {
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public void show(int page[])
	{
		for(int i=0;i<4;i++)
			System.out.print("\t"+page[i]);
		System.out.println();
	}
	public fifo() throws  IOException
	{
		int n,i,j,hit=0,mis=4,findex,flag;
		System.out.println("enter the no of processes");
		n=Integer.parseInt(br.readLine());
		int[] page =new int[4];
		int[] proc=new int[n];
		for(i=0;i<n;i++)
		{
			System.out.println("entre the processes");
			proc[i]=Integer.parseInt(br.readLine());
		}
		page[0]=proc[0];
		page[1]=proc[1];
		page[2]=proc[2];
		page[3]=proc[3];
		show(page);
		findex=0;
		for(i=4;i<n;i++)
		{
			flag=0;
			for(j=0;j<4;j++)
			{
				if(page[j]==proc[i])
				{
					flag=1;
					hit++;
					break;
				}
			}
			if(flag==0)
			{
				mis++;
				if(findex==3)
				{
					page[findex]=proc[i];
					findex=0;
				}
				else
				{
					page[findex]=proc[i];
					findex++;
				}
			}
			show(page);
		}
		System.out.println("number of hit "+hit);
		System.out.println("number of miss "+mis);
	}
	public static void main(String[] args) throws IOException
	{
		new fifo();
	}

}
