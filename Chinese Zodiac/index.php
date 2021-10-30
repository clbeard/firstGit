<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN">
<html lang ="en">
    <head>
    <title>Chinese Zodiac</title>
        <meta charset="utf-8">
       
    </head>
    <body>
         <center>
        <?php
        include 'Includes/inc_header.php';
             
        ?>
      
        </center>
        
     <?php
        include 'Includes/inc_button_nav.php';
             
        ?>
   <center>
     <?php
        include 'Includes/inc_text_links.php';
             
        ?>
    </center>
   
        

        <p><?php
    If (isset($_GET['page'])) {
      switch ($_GET['page']) {
        case 'site_layout':
          include('includes/' . 'inc_site_layout.php');
          break;
        case 'control_structures':
          include('includes/' . 'inc_control_structures.php');
          break;
        case 'string_functions':
          include('includes/' . 'inc_string_functions.php');
          break;
        case 'web_forms':
          include('includes/' . 'inc_web_forms.php');
          break; 
        case 'midterm_assignment':
          include('includes/' . 'inc_midterm_assessment.php');
          break;
        case 'state_information':
          include('includes/' . 'inc_state_information.php');
          break;
        case 'user_templates':
          include('includes/' . 'inc_user_templates.php');
          break;
        case 'final_project':
          include('includes/' . 'inc_final_project.php');
          break;
        case 'home_page': // A value of 'home_page' means to display the default page
        default:
          include('includes/inc_home.php');
          break;
        }
    } else { 
      // If no button has been selected, then display the default page
      include('includes/inc_home.php');
    }
?></p>
    
    
    <footer>
        <?php
        include 'Includes/inc_footer.php';
        ?>
        
        
        
        
        </footer>
    </body>
</html>