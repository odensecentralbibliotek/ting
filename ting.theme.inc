<?php

/**
 * @file
 * Theming functions for ting.
 */

/**
 * Template preprocessor for ting objects.
 */
function template_preprocess_ting_object(&$variables) {
  $variables['object'] = $variables['elements']['#object'];

  $variables['page'] = $variables['elements']['#view_mode'] == 'full';
  $variables['classes_array'][] = drupal_html_class('view-mode-' . $variables['elements']['#view_mode']);
  // Helpful $content variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  if ( isset($variables['content']['entities']) ) {
    foreach ( $variables['content']['entities'] as $key => $val ) {
      $variables['content']['overview']['types'][] = $key;
    }
  }
  /*
   * Add the material description to the material if conditions are met.
   */
  if(variable_get('oc_material_descriptions_enabled',0))
  {
    $node = menu_get_object();
    if(isset($node) && $node->type == "ding_news")
    {
        $t_id = $variables['object']->tid; // the correct id for the material.
        $description = "";
        foreach($node->field_ding_news_materials['und'] as $key => $relation)
        {
            $relation_id = $relation['value']->endpoints['und'][1]['entity_id'];
            if($relation_id == $t_id )
            {
                //We found the relationship index.
                $description  = isset($node->field_ding_news_material_descrip['und'][$key]['value']) 
                        && $node->field_ding_news_material_descrip['und'][$key]['value'] != "." 
                        ? $node->field_ding_news_material_descrip['und'][$key]['value'] : '';
                

                break;
            }
        }
        $variables['material_description'] =  $description;
    }
    if(isset($node) && $node->type == "ding_page")
    {
        $t_id = $variables['object']->tid; // the correct id for the material.
        $description = "";
        foreach($node->field_ding_page_materials['und'] as $key => $relation)
        {
            $relation_id = $relation['value']->endpoints['und'][1]['entity_id'];
            if($relation_id == $t_id )
            {
                //We found the relationship index.
                $description  = isset($node->field_ding_page_material_descrip['und'][$key]['value']) 
                        && $node->field_ding_page_material_descrip['und'][$key]['value'] != "." 
                        ? $node->field_ding_page_material_descrip['und'][$key]['value'] : '';
                

                break;
            }
        }
        $variables['material_description'] =  $description;
    }
  }

}

/**
 * Helper function to format abstracts from ting.
 */
function ting_format_abstract($string) {
  $string = str_replace('Indhold:', '', $string);
  $string = str_replace(' ; ', '<br/>', $string);
  $string = str_replace(' / ', '<br/>', $string);

  return $string;
}
