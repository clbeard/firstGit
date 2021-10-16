using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

public class videoControl : MonoBehaviour
{
    public VideoPlayer videoPlayer;
    public bool shouldPlay = false;
    public VideoClip[] myClips;
    public int currentClip = 0;

    public void nextVideo()
    {
        currentClip++;
        pauseVideo();
        rewindVideo();
        if (currentClip > myClips.Length - 1)
        {
            currentClip = 0;
        }

        videoPlayer.clip = myClips[currentClip];
    }

    public void previousVideo()
    {
        currentClip--;
        pauseVideo();
        rewindVideo();

        if (currentClip < 0)
        {
            currentClip = myClips.Length - 1;
        }
        videoPlayer.clip = myClips[currentClip];
    }


    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (shouldPlay)
        {
            videoPlayer.Play();

        }
        else
        {
            videoPlayer.Pause();
        }
    }


    public void playVideo()
    {
        shouldPlay = true;
    }
    public void pauseVideo()
    {
        shouldPlay = false;
    }

    public void rewindVideo()
    {
        videoPlayer.frame = 0;
        shouldPlay = false;
    }
}
