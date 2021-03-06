<?php
/**
 * @file
 * cc_content_list_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cc_content_list_features_image_default_styles() {
  $styles = array();

  // Exported image style: cc_content_list_item.
  $styles['cc_content_list_item'] = array(
    'name' => 'cc_content_list_item',
    'label' => 'cc_content_list_item',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 588,
          'height' => 364,
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
function cc_content_list_features_paragraphs_info() {
  $items = array(
    'content_list' => array(
      'name' => 'Content List',
      'bundle' => 'content_list',
      'locked' => '1',
    ),
    'content_list_item' => array(
      'name' => 'Content List Item',
      'bundle' => 'content_list_item',
      'locked' => '1',
    ),
  );
  return $items;
}
