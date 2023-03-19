/*histogram*/
package as3;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class intensity extends JFrame {


	 BufferedImage img = null,img2=null;
	    File f = null;
	    int c=0;
	    int inten[]=new int[260];
	    int max=0;		
	    public intensity() throws IOException
	    {
	    	
	    	this.setVisible(true);
			this.setSize(28000, 600);
			this.setBackground(Color.black);
			this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	    	
	    	
	    	  try{
			      f = new File("p2.png");
			      img = ImageIO.read(f);
			    }catch(IOException e){
			      System.out.println(e);
			    }

			    //get image width and height
			    int width = img.getWidth();
			    int height = img.getHeight();

			    //convert to grayscale
			    for(int y = 0; y < height; y++)
			    {
			      for(int x = 0; x < width; x++)
			      {
			    	  c++;
			        int p = img.getRGB(x,y);

			        int a = (p>>24)&0xff;
			        int r = (p>>16)&0xff;
			        int g = (p>>8)&0xff;
			        int b = p&0xff;

			        //calculate average
			        int avg = (r+g+b)/3;
			        inten[avg]++;
			        //System.out.println("S.No: " + c +" intensity "+avg);
			        
			        /*if(c%1000==0)
			        {
			        	 System.out.print("Enter a character: ");

			        // Read it and cast it to char 
			        char ch= (char) System.in.read();
			        
			        }
			         */
			    }
	    }
			    for(int i=0;i<=255;i++)
			    {
			    if(max<inten[i])
			    	max=inten[i];			    
			    	System.out.println("intensity " + i +" has "+inten[i]+"no of pixel");
			    }
			    System.out.println("max " + max );
			    repaint();
	    }
	    
	    @Override
		public void paint(Graphics g) {
			super.paint(g);
			Graphics2D g2d = (Graphics2D) g;
			g.setColor(Color.black);
			g.drawLine(10, 10, 10, 500);
			g.drawLine(10, 500, 25800, 500);
			g.setColor(Color.blue);
			 for(int i=0;i<=255;i++)
			    {
			    	g.drawLine(10+inten[i],500, 10+inten[i], 600-100-i);		    
			    	//System.out.println("intensity " + i +" has "+inten[i]+"no of pixel");
			    }
			
			//g2d.drawImage(img,0, 0, 400, 500, null);
			//g2d.drawImage(img2,401, 0, 400, 500, null);
		}
	    
	    public static void main(String args[])throws IOException{
	    	  
	  	  new intensity();
	  	  
	    }
}