<?php

$DisplayForm = True;
$Year = "";

if(isset($_POST['Submit'])){
    
    $Year = $_POST['Year'];
    
    if(is_numeric($Year)){
        $DisplayForm = FALSE;
        
    }else {
        echo "<p>You need a numeric value</p>";
    }
}

if($DisplayForm){
    ?>
<form name = "yearForm" action="BirthYear_ifelse.php"
      method="post">

<p>Enter your year: <input type ="text" name="Year"
                           value="<?php echo $Year; ?>"></p>
<p><input type= "submit" name="submit" value="send form">
    </p>
</form>
<?php

}else{
    switch($Year % 12)
    {
        case 0:
            
            echo"<p>You were born under the sign of the Monkey.</p>";
            echo"<p><img src = 'Images/monkey.png'></p>";
           
            
            break;
            
         
            
            
    }
}









?>