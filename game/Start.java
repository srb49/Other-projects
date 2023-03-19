package G23;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;


public class Start extends JFrame
{
	JPanel panel1,panel2,panel3,panel4;
	JButton b1,b2,b3,b4;
	Image bgimg,bgins;
	JFrame fm1,frame1,fm2;
	JLabel l1,l2,l3;
	JScrollPane scroll;
		//constructor
		public Start() 
		{
			fm1=new JFrame();
			fm2=new JFrame();
            initcomponent();
            setcomponent();
            fm1.setVisible(true);
            fm1.setDefaultCloseOperation(EXIT_ON_CLOSE);
            
		}
		public void initcomponent()
		{
			panel1=new JPanel();
			panel1.setBackground(Color.black);
			b1=new JButton("PLAY");
			b2=new JButton("HELP");
			b3=new JButton("QUIT");
			panel1.add(b1);
			panel1.add(b2);
			panel1.add(b3);
			
			bgimg=new ImageIcon(getClass().getResource("/still/start.jpg")).getImage();
			l1=new JLabel();
			l1.setIcon(new ImageIcon(bgimg));
			l1.setBounds(0, 0, fm1.MAXIMIZED_HORIZ, fm1.MAXIMIZED_VERT);
			panel2=new JPanel();
			panel2.setBackground(Color.BLACK);
			panel2.add(l1);
		
			fm1.add(panel1,BorderLayout.NORTH);
			fm1.add(panel2,BorderLayout.CENTER);
			fm1.setTitle("SEA WORLD");
			fm1.setExtendedState(fm1.MAXIMIZED_BOTH);
			
			//fm1.setSize(MAXIMIZED_HORIZ, MAXIMIZED_VERT);
		}
		
		public void setcomponent()
		{
			b1.addActionListener(new ActionListener(){

				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO Auto-generated method stub
					 frame1 = new JFrame();
					 fm1.setVisible(false);
					 if(fm2.isVisible())
					 fm2.setVisible(false);
					Dboard d1=new Dboard();
	                frame1.add(d1);
	                frame1.setTitle("SEA WORLD");
	                frame1.setExtendedState(frame1.MAXIMIZED_BOTH);	 
	                frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	                frame1.setVisible(true); 
	                setExtendedState(MAXIMIZED_BOTH);
	                
				}
				
				
			});
			b2.addActionListener(new ActionListener(){

				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO Auto-generated method stub

					panel3=new JPanel();
	                panel3.setBackground(Color.orange);
	                panel3.add(b1);
	                panel3.add(b3);
	                
	                panel4=new JPanel();
	                panel4.setBackground(Color.GRAY);
	                fm2.add(panel3,BorderLayout.NORTH);
	                
	                bgins=new ImageIcon(getClass().getResource("/still/ins.png")).getImage();
	    			l3=new JLabel();
	    			l3.setIcon(new ImageIcon(bgins));
	    			l3.setBounds(0, 0, fm2.MAXIMIZED_HORIZ, fm2.MAXIMIZED_VERT);
	    			panel4.add(l3);
	    			scroll = new JScrollPane(panel4);
	    			scroll.setAutoscrolls(true);
	    			fm2.add(scroll);
	    			fm1.setVisible(false);
	    			fm2.setVisible(true);
	    			fm2.setExtendedState(fm2.MAXIMIZED_BOTH);
	    			fm2.setDefaultCloseOperation(EXIT_ON_CLOSE);

				}	
				
			});
			
			
			b3.addActionListener(new ActionListener(){

				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO Auto-generated method stub
					System.exit(0);
				}
				
			});
		}
		
		public static void main(String[] args) 
		{
			new Start();//constructor is called

		}

	}

