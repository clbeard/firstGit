<!DOCTYPE html>
<html lang ="en">
    <head>
    <title>Years and Animals</title>
        <meta charset="utf-8">
        
    </head>
    
   
     <body>

    <table border = 1>
         
         
         
      
         
         <?php
        
 
            $Cycle = 0; 
         $Years = 1912;
         
        $AnimalArray = array("Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig");
        
        echo "<tr>";
        
       $Count = 0;
    
        echo "</tr>";
        
        echo "<tr>";
        
        $Count = 0;
    while($Count < 12){
            
             echo "<td><img src = '$AnimalArray[$Count].png' 
            width = 75></td>";
            $Count++;
        
        }
        echo "</tr>";
        
        $Cylce = 0;
        $Years = 1911;
        while($Years < 2018)
        {
            $Years++;
            if($Cycle >= 12){
                
                $Cycle = 0;
                echo"<tr></tr>";
                echo "<td>$Years</td>";
                
            }
            else {
                echo"<td>$Years</td>";
                
            }
            $Cycle++;
        }
    
    
    ?>
    
       </table>
    </body>
        
        
    
    
    
    
</html>
    
    
    
   
   
  
                