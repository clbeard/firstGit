using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class slideShow : MonoBehaviour
{
    public Sprite[] imageArray;

    public int currentImage =0;

    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Image>().sprite = imageArray[currentImage];
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void moveLeft()
    {
        currentImage--;

        if(currentImage < 0)
        {
            currentImage = imageArray.Length - 1;
        }

        GetComponent<Image>().sprite = imageArray[currentImage];
    }

     public void moveRight()
    {
        currentImage++;

        if(currentImage > imageArray.Length -1)
        {
            currentImage = 0;
        }

        GetComponent<Image>().sprite = imageArray[currentImage];
    }
}
