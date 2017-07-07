<?php
/**
 * @file
 * cmb_field_bases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cmb_field_bases_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cmb_field_bases_node_info() {
  $items = array(
    'cmb_field_bases_dummy' => array(
      'name' => t('CMB Field Bases Dummy'),
      'base' => 'node_content',
      'description' => t('This is a "dummy" content type in order to create "field instances" of the "field bases" defined in CMB Field Bases feature. This allows other content types to use the fields defined here, otherwise fields with no instances arent available.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
