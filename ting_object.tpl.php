<?php
// $Id$
/**
 * @file ting_object.tpl.php
 *
 * Template to render objects from the Ting database.
 *
 * Available variables:
 * - $object: The TingClientObject instance we're rendering.
 * - $content: Render array of content.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php 
    if(isset($material_description) && $material_description != "")
    {
        echo t('<br/><h4><b>Bibliotekarens noter:</b></h4> ') .$material_description;
        echo "<br/>";
    }
    echo render($content);
    
    ?>

</div>
