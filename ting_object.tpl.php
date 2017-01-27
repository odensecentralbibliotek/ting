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
    echo render($content);
    ?>
    <?php
    if(isset($material_description) && $material_description != "")
    {
    ?>
    <style>
        .ting-object{
            box-shadow: 0 4px 8px 0 rgba(0,0,0,0.2);
            transition: 0.3s;
            padding: 5px;
        }
    </style>
    <?php
        echo "<div>";
        echo t('<br/><h4><b>Bibliotekarens noter:</b></h4> ') .$material_description;
        echo "<br/></div>";
    }
    ?>

</div>
