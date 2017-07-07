<?php

function _page__cm_show(&$variables) {
  $node = $variables['node'];

  // cmb_show_meta_left
  $cmb_show_meta_left_node_view = node_view($node, 'cmb_show_meta_left');
  $cmb_show_meta_left_node_render = drupal_render($cmb_show_meta_left_node_view);

  // cmb_show_meta_right
  $cmb_show_meta_right_node_view = node_view($node, 'cmb_show_meta_right');
  $cmb_show_meta_right_node_render = drupal_render($cmb_show_meta_right_node_view);

  // Add social media block
  $social_media_block_render = FALSE;
  if (module_exists('widgets')) {
    $social_media_block = module_invoke('widgets', 'block_view', 's_socialmedia_share-default');
    $social_media_block_render = $social_media_block['content'];
  }

  $data = [
    'nid' => $node->nid,
    'title' => $node->title,
    'cmb_show_meta_left' => $cmb_show_meta_left_node_render,
    'cmb_show_meta_right' => $cmb_show_meta_right_node_render,
    'social_media_block' => $social_media_block_render,
  ];

  $variables['page__cm_show'] = $data;
}
