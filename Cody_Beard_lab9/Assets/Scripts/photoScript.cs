using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class photoScript : MonoBehaviour
{
    public RawImage rawImage;
    public WebCamTexture cameraTex;

    public int captureCounter = 0;

    public void takeSnapshot()
    {
        Texture2D snap = new Texture2D(cameraTex.width,cameraTex.height);

        snap.SetPixels(cameraTex.GetPixels());

        snap.Apply();

            #if UNITY_EDITOR
                System.IO.File.WriteAllBytes(Application.dataPath + captureCounter.ToString() + ".png", snap.EncodeToPNG());


            #elif UNITY_IOS
            System.IO.File.WriteAllBytes(Application.persistentDataPath + captureCounter.ToString() + ".png", snap.EncodeToPNG());

            #endif
            ++captureCounter;
            PlayerPrefs.SetInt("counter",captureCounter);
            PlayerPrefs.Save();
    }
    // Start is called before the first frame update
    void Start()
    {
        WebCamTexture webCamTexture = new WebCamTexture();
        webCamTexture.requestedWidth = 800;
        webCamTexture.requestedHeight = 600;

        rawImage.texture = webCamTexture;
        rawImage.material.mainTexture = webCamTexture;

        webCamTexture.Play();

        cameraTex = webCamTexture;

        if(PlayerPrefs.HasKey("Counter"))
        {
            captureCounter = PlayerPrefs.GetInt("counter");
        }else
        {
            PlayerPrefs.SetInt("counter",0);
            PlayerPrefs.Save();
            captureCounter = PlayerPrefs.GetInt("counter");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
