package as3;

/**
 * File: Grayscale.java
 * 
 * Description:
 * Convert color image into grayscale image.
 *
 * @author Yusuf Shakeel
 * Date: 26-01-2014 sun
 *
 * www.github.com/yusufshakeel/Java-Image-Processing-Project
 */
import java.io.File;
import java.io.IOException;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class GrayScale extends JFrame{
	

	 BufferedImage img = null,img2=null;
	    File f = null;
	    
	public GrayScale()
	{
		
		this.setVisible(true);
		this.setSize(800, 500);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		    //read image
		    try{
		      f = new File("E:\\MSc\\2nd sem\\bs\\prac\\img1\\2.jpg");
		      img = ImageIO.read(f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

		    //get image width and height
		    int width = img.getWidth();
		    int height = img.getHeight();

		    //convert to grayscale
		    for(int y = 0; y < height; y++){
		      for(int x = 0; x < width; x++){
		        int p = img.getRGB(x,y);

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

		    //write image
		    try{
		      f = new File("E:\\MSc\\2nd sem\\bs\\prac\\img1\\Output2.jpg");
		      ImageIO.write(img, "jpg", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }
		    
		      //read image
			    try{
			    	f = new File("E:\\MSc\\2nd sem\\bs\\prac\\img1\\2.jpg");
				      img2 = ImageIO.read(f);
			    }catch(IOException e){
			      System.out.println(e);
			    }
		    repaint();
	}
	
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		Graphics2D g2d = (Graphics2D) g;
		
		g2d.drawImage(img,0, 0, 400, 500, null);
		g2d.drawImage(img2,401, 0, 400, 500, null);
	}
	
  public static void main(String args[])throws IOException{
  
	  new GrayScale();
	  
  }
  //main() ends here
  
}//class ends here