package G23;

import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;

import javax.swing.ImageIcon;

public class Fish implements KeyListener{

	enum State{
		STANDING, RUNNING
	}
	enum Direction{
		LEFT, RIGHT
	}
	State state=State.STANDING;
	Direction dir = Direction.RIGHT;
	 
	int x, dx=0,y,nx2,nx,x0,y0,f=1,nx1,nx21,dx1=1; 
    int flag=0,sh=1,pntm=0,rf=0;
    
    Sound gunM;
	
	Image still;
    Image l1=new ImageIcon(getClass().getResource("/still/l.png")).getImage();
    Image r1 =  new ImageIcon(getClass().getResource("/still/f.png")).getImage();
    

    Image[] runningSprite = new Image[10];
	Image[] runningSprite1 = new Image[10];
	int runningSpriteCount1 = 0;
	int runningSpriteCount2 = 0;  
	
	public Image getImage() {
        return still;
	}
	
	static ArrayList bl;//Holds number of bullets on screen
    public static ArrayList getBullets()
    {
            return bl;
    }
    
	public Fish(int x, int y) {
		this.x = x0 = x;//10 from start
		this.y = y0 = y;//300 
		
		still=r1;
        nx2=1360;
        nx=0;
        bl = new ArrayList();
        
        for(int i=0;i<=7;i++)
			runningSprite[i] = new ImageIcon(getClass().getResource("/run1/0"+i+".png")).getImage();
	
        for(int i=0;i<=7;i++)
			runningSprite1[i] = new ImageIcon(getClass().getResource("/run2/0"+i+".png")).getImage();
        gunM=new Sound("/music/g1.mp3");
	}
	
	public Rectangle area()
	{
		return new Rectangle(x,y,220,150);
	}
	
	public int getX() {
        return x;
	}

	public int getY() {
        return y;
	}
	public void fire()
	{
		
		Bullet b1=new Bullet(this.getX()+230,this.getY()+80,this.nx2);
		if(bl.size()<=5) 
		{
			gunM.play();
			gunM.stop();
			bl.add(b1);
			
		}
	}
	public void draw(Graphics2D g,int wid) {
		
		sh++;
		if(state==State.STANDING)
		{
			pntm=0;
			rf=0;
			g.drawImage(still,this.getX(),this.getY(),null);
			flag=0;
		}
		else if(state==State.RUNNING){
			
			if(dir==Direction.RIGHT){
				
				flag=1;
				dx=5;
				if(f==0)
				{
					f=1;
					nx2=nx21;
					nx=nx1;
				}
				g.drawImage(runningSprite[runningSpriteCount1],x,y,null);
				runningSpriteCount1 = (runningSpriteCount1+1)%10;
				if(x<wid-300)
				x=x+dx1;
				if(x0>58&&(x0-50)%1395==0)
				{
					x0=50;
					nx2=1400;
					nx=0;
				}
				x0=x0+dx;
				still=r1;
				nx2=nx2+dx;
				if(x0>=55)
	            nx=nx+dx;
								
			}
			else if(dir==Direction.LEFT){
				pntm=0;
				flag=0;
				g.drawImage(runningSprite1[runningSpriteCount2],x,y,null);
				runningSpriteCount2 = (runningSpriteCount2+1)%10;
				if(x>0)
				x=x-dx1;
				still=l1;
			}
			try {
				Thread.sleep(30);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public void keyPressed(KeyEvent ke) {
		
		if(ke.getKeyCode() == KeyEvent.VK_UP){
			if(y-5>=0)
			y=y-5;
			pntm=0;
			rf=0;
		}
		
		else if(ke.getKeyCode() == KeyEvent.VK_DOWN){
			if(y+5<=450)//got by checking
			y=y+5;
			pntm=0;
			rf=0;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_SPACE){
			fire();
			pntm=0;
			rf=0;
		}
		else if(ke.getKeyCode()==KeyEvent.VK_RIGHT){
			dir = Direction.RIGHT;
			state = State.RUNNING;
			dx1=1;
			pntm=1;rf=1;
		}
		
		else if(ke.getKeyCode()==KeyEvent.VK_LEFT){
			dir = Direction.LEFT;
			state = State.RUNNING;
			dx1=2;
			pntm=0;rf=1;
		}
		
		else if(ke.getKeyCode()==KeyEvent.VK_R){
			dx1=2;
			dir = Direction.RIGHT;
			state = State.RUNNING;
			pntm=1;rf=2;
		}
		else if(ke.getKeyCode()==KeyEvent.VK_L){
			dir = Direction.LEFT;
			state = State.RUNNING;
			dx1=4;
			pntm=0;rf=2;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		state= State.STANDING;
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}
