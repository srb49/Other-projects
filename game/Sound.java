package G23;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class Sound {
	
	Clip clip;
	public Sound(String s)
	{
		try
		{
			AudioInputStream snd=AudioSystem.getAudioInputStream(getClass().getResourceAsStream(s));
			AudioFormat baseFormat= snd.getFormat();
			
			AudioFormat decodeFormat=new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, baseFormat.getSampleRate(),16,
					baseFormat.getChannels(),baseFormat.getChannels()*2,baseFormat.getSampleRate(),false);
			AudioInputStream dsnd=AudioSystem.getAudioInputStream(decodeFormat,snd);
			clip=AudioSystem.getClip();
			clip.open(dsnd);
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
	public void play()
	{
		if(clip==null)
			return;
		stop();
		clip.setFramePosition(0);
		clip.start();
	}
	public void stop()
	{
		if(clip.isRunning())
			clip.stop();
	}
	
	public void play1()
	{
		clip.loop(Clip.LOOP_CONTINUOUSLY);
	}
}
