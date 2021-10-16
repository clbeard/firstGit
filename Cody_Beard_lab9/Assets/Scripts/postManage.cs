using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class postManage : MonoBehaviour
{
    string myURL = "http://unityjumpstart.com/phpform/postData3.php";
    public InputField nameIF,addressIF,cityIF,stateIF,commentsIF;


    public void SendMail()
    {
        var nameFix = MyEscapeURL(nameIF.text);
        myURL += "?name=" + nameFix;

        var addressFix = MyEscapeURL(addressIF.text);
        myURL += "&address=" + addressFix;

        var cityFix = MyEscapeURL(cityIF.text);
        myURL += "&city=" + cityFix;

        var stateFix = MyEscapeURL(stateIF.text);
        myURL += "&state=" + stateFix;

        var commentsFix = MyEscapeURL(commentsIF.text);
        myURL += "&comments=" + commentsFix;

        Application.OpenURL(myURL);
    }


    public void clearFields()
    {

        nameIF.text = "";
        addressIF.text = "";
        cityIF.text = "";
        stateIF.text = "";
        commentsIF.text = "";



    }

    string MyEscapeURL(string url)
    {
        return WWW.EscapeURL(url).Replace("+", "%20");
    }

}
