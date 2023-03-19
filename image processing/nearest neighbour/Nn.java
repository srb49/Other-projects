/*nearest neighbor interpolation*/
package as1;

import java.io.File;
import java.io.IOException;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.JFrame;


//import java.awt.*;
//import java.awt.image.BufferedImage;

import java.io.*;

public class Nn extends JFrame {
	BufferedImage img=null,img1=null;
	File f=null;
	int sx,sy,x1,y1,x,y,p,width,height;
	float xi,yi;
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public Nn() throws IOException
	{
		//this.setSize(800,500);
		//this.setVisible(true);
		//this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		try
		{
			f=new File("1.jpg");
			img=ImageIO.read(f);
		}
		catch(IOException e)
		{
			System.out.println(e);
		} //get image width and height
	    
		 width = img.getWidth();
	     height = img.getHeight();
	     System.out.println(width+" "+height);

	    //convert to grayscale
	    for( y = 0; y < height; y++){
	      for( x = 0; x < width; x++){
	         p = img.getRGB(x,y);

	        int a = (p>>24)&0xff;
	        int r = (p>>16)&0xff;
	        int g = (p>>8)&0xff;
	        int b = p&0xff;

	        //calculate average
	        int avg = (r+g+b)/3;

	        //replace RGB value with avg
	        p = (a<<24) | (avg<<16) | (avg<<8) | avg;
	        img.setRGB(x, y, p);
	        
	       
	      }
	    }		
	    System.out.println("enter sx");
        sx=Integer.parseInt(br.readLine());
        System.out.println("enter sy");
        sy=Integer.parseInt(br.readLine());
       
        inter(sx,sy);
		//repaint();
	}
	
	/*nearest neighbor interpolation*/
	public void inter(int sx,int sy)
	{
		 
	        x1=sx*width;
	        y1=sy*height;
	        img1 = new BufferedImage(x1, y1, BufferedImage.TYPE_INT_ARGB);
	        for(int i=0;i<y1;i++)
	        {
	        	for(int j=0;j<x1;j++)
	        	{
	        		x=j/sx;
//	        		x=Math.round(xi);
	        		
	        		y=i/sy;
//	        		y=Math.round(yi);
	        		System.out.println(x+" "+y);
	        		p=img.getRGB(x, y);
	        		img1.setRGB(j, i, p);
	        	}
	        }
	        
	        //write image
		    try{
		      f = new File("Output1.jpg");
		      ImageIO.write(img1, "jpg", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }
	}
	
	public static void main(String args[])throws IOException
	{
		new Nn();
		 
	}

}
