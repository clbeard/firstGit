using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

public class cameraMove : MonoBehaviour
{
    public float speedFactor = 0.1f;
    public Transform currentAnchor;
    public AudioSource slide,background;

    public GameObject videoScreen;

    public void musicPause()
    {
        background.Pause();
    }

    public void playMusic()
    {
        background.Play();

        videoScreen.GetComponent<videoControl>().shouldPlay = false;
        videoScreen.GetComponent<videoControl>().rewindVideo();
    }


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //move camera
        transform.position = Vector3.Lerp(transform.position, currentAnchor.position,speedFactor);

        //rotate camera
        transform.rotation = Quaternion.Slerp(transform.rotation,currentAnchor.rotation,speedFactor);


    }

    public void setAnchor(Transform anchor)
    {
        //play audio source
        slide.Play();

        //set new anhcor point ot move to
        currentAnchor = anchor; 
    }
}
