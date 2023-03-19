package as2;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.stream.IntStream;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class Nr extends JFrame {

	BufferedImage img = null, img1 = null;
	File f = null;
	int k = 10, i, s = -1;
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public Nr() {

		// this.setVisible(true);
		// this.setSize(800, 500);
		// this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		// noise creation for 10 images
		for (i = 0; i < 10; i++) {
			// read image
			try {
				f = new File("p1.png");
				img = ImageIO.read(f);
			} catch (IOException e) {
				System.out.println(e);
			}

			// get image width and height
			int width = img.getWidth();
			int height = img.getHeight();
			int threashold = (int) (width*height * 0.5);

			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					int p = img.getRGB(x, y);
					// s=s*s;
					Random rand = new Random();
					if (rand.nextBoolean() && rand.nextBoolean() && rand.nextBoolean() && rand.nextBoolean()) {
						// int randomNum = rand.nextInt((10000 - 0) + 1);
						int val = rand.nextBoolean()? 0 : 255;
						Color c = new Color(val, val, val);
						p = c.getRGB();
					}
					// System.out.println( randomNum );
					// p=(p+randomNum)*s;
					// if(p<0)
					// p=p*-1;
					img.setRGB(x, y, p);
//					System.out.println(p);
				}
			}

			// write image
			try {
				f = new File("noise" + File.separator + i + ".jpg");
				ImageIO.write(img, "jpg", f);
			} catch (IOException e) {
				System.out.println(e);
			}
		}
		// noise reduction
		n_red();
	}

	public void n_red() {

		// try{
		// f = new File("E:\\MSc\\2nd sem\\bs\\prac\\img1\\p1.png");
		// img = ImageIO.read(f);
		// }catch(IOException e){
		// System.out.println(e);
		// }
		// get image width and height
		int width = img.getWidth();
		int height = img.getHeight();
		img1 = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);

		BufferedImage[] imgs = new BufferedImage[10];
		for (i = 0; i < 10; i++) {
			try {
				f = new File("noise" + File.separator + i + ".jpg");
				imgs[i] = ImageIO.read(f);
			} catch (IOException e) {
				System.out.println(e);
			}
		}

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int r=0, g=0, b=0;
				for (i = 0; i < 10; i++) {
					int p = imgs[i].getRGB(x, y);
					Color c = new Color(p);
					r += c.getRed();
					g += c.getGreen();
					b += c.getBlue();
					// System.out.println(sum);
				}
//				System.out.println(r/10+" "+g/10+" "+b/10);
				Color c = new Color(r/10, g/10, b/10);
//				 System.out.println(c.getRGB());
				img1.setRGB(x, y, c.getRGB());
			}
			System.out.println(y);
		}
		// write image
		try {
			f = new File("p2.png");
			ImageIO.write(img1, "png", f);
		} catch (IOException e) {
			System.out.println(e);
		}

	}

	public static void main(String args[]) throws IOException {

		new Nr();

	}
}