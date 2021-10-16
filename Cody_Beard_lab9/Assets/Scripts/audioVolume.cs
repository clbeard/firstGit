using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class audioVolume : MonoBehaviour
{
    public AudioSource myAudio;

    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Slider>().value = .5f;

        myAudio.volume = GetComponent<Slider>().value;
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void onChangeVolume()
    {
        myAudio.volume = GetComponent<Slider>().value;
    }
}
