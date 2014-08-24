<!DOCTYPE html>

<?php

/**
Erkennung aufgrund von Account Ranges ob es sich um eine Corporate Card handelt und zu welchem Account diese gehört
Rückgabe eines Fehlers wenn ein nicht vorhandenes Token angefragt wird
Löschen eines Datensatzes auf DB ebene
Löschen aller Datensätze auf DB-Ebene
Automatisiertes Löschen von Datensätzen auf die seit 10 Jahren nicht zugegriffen wurde.
*/


$s['set_token_by_pan']             = array('description' => "Erstmalige Transition der in den DB / Tabellen vorhandenen PAN zu Token.", 
            		       		   'input_field' => "Pan", 
            		       		   'placeholder' => "1111-1111-1111-1111"); 
$s['get_pan_by_token'] 		   = array('description' => "Ermitteln der Kartennummer zum Token", 
            		       		   'input_field' => "Token", 
            		       		   'placeholder' => "6ab7b7cb99699410f5e715ca6cd1a3344a7dd1c19cdcf956cd26a877d515fa"); 
$s['get_token_six_four_by_token']  = array('description' => "Rückgabe einer maskierten Kartennummer (z.B. 6-4)", 
            		       		   'input_field' => "Token", 
            		       		   'placeholder' => "6ab7b7cb99699410f5e715ca6cd1a3344a7dd1c19cdcf956cd26a877d515fa"); 
$s['get_provider_by_pan'] 	   = array('description' => "Ermitteln einer Kartenorganisation zu einer Kartennummer", 
            		       		   'input_field' => "Pan", 
            		       		   'placeholder' => "1111-1111-1111-1111"); 
$s['get_provider_by_token'] 	   = array('description' => "Ermitteln einer Kartenorganisation zu einem Token", 
            		       		   'input_field' => "Token", 
            		       		   'placeholder' => "6ab7b7cb99699410f5e715ca6cd1a3344a7dd1c19cdcf956cd26a877d515fa"); 
$s['get_card_type_by_token'] 	   = array('description' => "Ermitteln der Kartenart (Credit/Debit) zu einem Token", 
            		       		   'input_field' => "Token", 
            		       		   'placeholder' => "6ab7b7cb99699410f5e715ca6cd1a3344a7dd1c19cdcf956cd26a877d515fa"); 
$s['get_card_type_by_pan'] 	   = array('description' => "Ermitteln der Kartenart (Credit/Debit) zu einer Kartennummer", 
            		       		   'input_field' => "Token", 
            		       		   'placeholder' => "6ab7b7cb99699410f5e715ca6cd1a3344a7dd1c19cdcf956cd26a877d515fa"); 
$s['get_tokens_by_token_six_four'] = array('description' => "Ermitteln der vorhandenen Tokens zu einer maskierten Kartennummer", 
            		       		  'input_field' => "Token Six Four", 
            		       		  'placeholder' => "111111xxxxxx1111"); 
$s['get_count_tokens_by_token_six_four'] = array('description' => "Anzahl der zu einer maskierten Kartennummer gespeicherten Token.", 
            		       		  'input_field' => "Token Six Four", 
            		       		  'placeholder' => "111111xxxxxx1111"); 

$buttons = implode(",#button_",array_keys($s));
?>


<html>
<head>
	<meta charset="utf-8">
	<title>PCI DSS Token Server</title>
	<link rel="stylesheet" media="screen" href="styles.css" >
	<script src="http://code.jquery.com/jquery-latest.js"></script>
</head>
<body>

<?php
foreach($s as $k => $v) {
?>

<form class="contact_form" action="" id="<?php print $k; ?>">
    <ul>
        <li class="r1">
             <h2><?php print $k; ?></h2>
             <button class="submit" id="button_<?php print $k; ?>">:: RUN ::</button>
        </li>
        <li class="r2">
             <h4>Description:</h4>
             <span><?php print $s[$k]['description']; ?></span>
        </li>
        <li class="r3">
            <label for="name"><?php print $v['input_field']; ?>:</label>
	       <input type="text" name="data" id="data" placeholder="<?php print $v['placeholder']; ?>" required />
	       <input type="hidden" name="function" id="function" value="<?php print $k; ?>" />
	       <span class="required_notification">* Required Fields</span>
        </li>
        <li class="r4">
            <div id="result_<?php print $k; ?>"></div>
	</li>
    </ul>
</form>

<br>
<?php
}
?>

<script>
$(function(){
    $("<?php print "#button_". $buttons; ?>").click(function(e){
        e.preventDefault();
	//var id = $('#submit').closest('form').attr('id');
	
	var id = $(this).closest('form').attr('id');
 
        dataString = $("#"+id).serialize();
     
        $.ajax({
        type: "POST",
        url: "service.php",
        data: dataString,
        dataType: "json",
        success: function(data) {
	    $("#result_"+id).html("<strong>Result:</strong> " + data).fadeIn('slow');
	}
        });         
    });
});
</script>

</body>
</html>
