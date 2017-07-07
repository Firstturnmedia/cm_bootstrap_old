<?php
/**
 * @file
 * cc_image_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cc_image_features_image_default_styles() {
  $styles = array();

  // Exported image style: cc_image.
  $styles['cc_image'] = array(
    'label' => 'cc_image',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1500,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function cc_image_features_paragraphs_info() {
  $items = array(
    'image' => array(
      'name' => 'Image',
      'bundle' => 'image',
      'locked' => '1',
    ),
  );
  return $items;
}
