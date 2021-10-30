<!DOCTYPE html>
<html lang ="en">
    <head>
    <title>Years and Animals</title>
        <meta charset="utf-8">
        
    </head>
    
   
     <body>

    <table border = 1>
         
         
         
      
         
         <?php
        
 
             
         $Years = 1912;
         
        $AnimalArray = array("Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig");
        
        echo "<tr>";
        
        for($count = 0;$count < 12; $count++){
            
            
         echo"<td><img src = '$AnimalArray[$count].png' width = 100 height = 100 ></td>"; 
            
            
            
       
        }
        
        echo"</tr>";
         
         
         $counter = 0;
             for($Years = 1912;$Years < 2019; $Years++)
             {
                 if($counter == 12){
                                        
                     $counter = 0;
                     
                     echo "<tr>";
                     echo "<td>$Years</td>";
                     
                 }else
                 {
                      echo "<td> $Years </td>";
                 }
                 
                 
                 $counter++;
                     
                
                 
                 
                 
                 
             }
         
         
         
         
    
       echo "</tr>"; 
        
    
    
    ?>
    
       </table>
    </body>
        
        
    
    
    
    
</html>
    
    
    
   
   
  
                