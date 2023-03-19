package G23;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;

import G23.Fish.State;


public class Dboard extends JPanel implements ActionListener{

	Fish f1;
	Image img,fimg;
    Timer time;
    Shark s1;
    Start st;
    boolean lost=false;
    int fire=0,points=0,ene=0,col1=0,pnt=0,live=2;
    point p1;
    Sound sm;
    static Font font = new Font("SanSerif", Font.BOLD, 24);
    Sound bgmsc,pntM,collM,shM,gmoM;
	public Dboard()
	{
		f1=new Fish(10,300);
		addKeyListener(f1);
		setFocusable(true);
		 img = new ImageIcon(getClass().getResource("/still/s2.png")).getImage();
		 setFocusable(true);
		 
		 time = new Timer(10,this);
         time.start();
         s1=new Shark(f1.nx2,f1.getY());
         p1=new point(900,300);
         bgmsc=new Sound("/music/sea.mp3"); 
         pntM=new Sound("/music/p1.mp3");
         collM=new Sound("/music/c1.mp3");
         bgmsc.play1();
         
	}
	@Override
	public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;
        
        if(f1.x0<=48)
		{
		g2d.drawImage(img,1360-f1.nx2,0,null);
		//System.out.println(f1.x0+","+f1.nx2+","+f1.sh);
		}
        else
        {
		g2d.drawImage(img,1360-f1.nx,0,null);
		g2d.drawImage(img,1360-f1.nx2,0,null);
		//System.out.println(f1.x0+","+f1.nx2+","+f1.nx+","+f1.sh);
        //p1.print();
        }
        
        f1.draw(g2d,this.getWidth());
        
        ArrayList bullets = Fish.getBullets();
        for (int w = 0; w < bullets.size(); w++)
        {
                
            Bullet m = (Bullet) bullets.get(w);
            g2d.drawImage(m.getImage(), m.getX(), m.getY(), null);
            //sm.gun();

        }
        if(ene==1)
        {
        	if(s1.visible()==true)
        		g2d.drawImage(s1.getImage(), s1.getX(), s1.getY(), null);
        }
        if(fire==1)
        {
        	fimg=new ImageIcon(getClass().getResource("/still/fire.gif")).getImage();
         	g2d.drawImage(fimg, s1.getX(), s1.getY(), null);	
        	//fire=0;
        	repaint();
        }
        if(pnt==1)
        {
        	if(p1.visible()==true)
        		g2d.drawImage(p1.getImage(), p1.getX(), p1.getY(), null);
        }
        g2d.setFont(font);
        g2d.setColor(Color.YELLOW);
        g2d.drawString("Points: " + points, 30, 50);
        g2d.setColor(Color.black);
        g2d.drawString("lives " + live, this.getWidth()-100, 50);
        
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
		checkpoint();
		checkenemy();
		coll();
	
		ArrayList bullets = Fish.getBullets();
         for (int w = 0; w < bullets.size(); w++)
         {
                  Bullet m = (Bullet) bullets.get(w);
                  if (m.getVisible() == true)
                  {
                	  	
                          m.move();
                  }
                  else bullets.remove(w);
         }
         if(ene==1&&col1==0)
         {
        	 //s1=new Shark(f1.nx2,f1.getY());
        	 s1.a=true;
        	 s1.move(f1.rf);
          }
         if(pnt==1&&f1.pntm==1)
        	 p1.move();

         
		repaint();
	}
	public void checkenemy()
	{
		if(f1.sh%900==0&&ene==0)
		{	
			s1.x=this.getWidth();
			ene=1;
			s1.a=true;
			s1.generate(this.getHeight());
		}
		else if(f1.sh%1850==0&&ene==1)
		{
			
			ene=0;
			col1=0;
			s1.a=false;
		}	
	}
	public void checkpoint()
	{
		if(f1.sh%300==0&&pnt==0)
		{	
			int w=this.getWidth(),h=this.getHeight();
			p1.vis=true;
			p1.generate(w,h);
			pnt=1;
		}
		else if(f1.sh%500==0&&pnt==1)
		{
			p1.vis=false;
			pnt=0;
		}
	}
    public void coll()
    {
    	Rectangle r1=s1.area();
    	ArrayList bullets = Fish.getBullets();
        for (int w = 0; w < bullets.size(); w++)
        {
                 Bullet m = (Bullet) bullets.get(w);
                 Rectangle r2=m.area();
                 if(r1.intersects(r2) && s1.visible()==true)
                 {
                	col1=1;
                	 m.v=false;
                	 s1.a=false;
                	
                 }
                 //System.out.println("shark area "+r1+" bullet "+r2);
                	 
        }
        Rectangle r3=f1.area();
        if(r3.intersects(r1)&&s1.visible())
        {
        	// System.out.println("shark area "+r1+" fish "+r3);
        	 s1.a=false;
        	 s1.x=-500;
        	if(live==0)
        	{
        	bgmsc.stop();
        	shM=new Sound("/music/s11.mp3");
        	shM.play();
        	try{
        		Thread.sleep(3000);
        	}
        	catch(Exception e)
        	{}
        	gmoM=new Sound("/music/go.mp3");
        	gmoM.play();
        	Object[] options = {
                    "REPLAY",
                    "EXIT"};
        	int n = JOptionPane.showOptionDialog(this,
        			"SORRY...GAME OVER",
        			"NO LIVES LEFT",
        			JOptionPane.YES_NO_CANCEL_OPTION,
        			JOptionPane.QUESTION_MESSAGE,
        			null,
        			options,
        			options[1]);
        		if(n==1)
        		System.exit(0);
        		else if(n==0)
        		{
        		bgmsc.play1();
        		points=0;
            	live=2;
        		f1.x=f1.x0=10;
        		f1.y=300;
        		f1.nx2=1360;
        	    f1.nx=0;
        	    f1.still=f1.r1;
        	    s1.a=false;
        	    p1.vis=false;
        	    
        		}
        	}
        	else
        	{
        		bgmsc.stop();
        		collM.play();
        		JOptionPane.showMessageDialog(this,"OOPS...COLLISION!!!!Be careful next time");
        		bgmsc.play1();
        		live--;
        		s1.a=false;
        		f1.still=f1.r1;
        		f1.state=State.STANDING;
        	}
        	
        }
        Rectangle r4=p1.area();
        if(r3.intersects(r4)&&p1.visible())
        {
        	 //System.out.println("fish area area "+r3+" food "+r4);
        	pntM.play();
        	points++;
        	p1.vis=false;
        	//System.out.println(points);
        }
       // System.out.println("shark  "+s1.getX()+" fishx "+f1.getX()+"  pointx  "+p1.getX()+"  visp "+p1.vis+" points "+points);
    }
	
}
