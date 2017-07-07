<?php

function _cmb_cb_shows_in_series() {
  if ($current_node = menu_get_object()) {
    switch($current_node->type) {
      case 'cm_show':
        if (isset($current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
          $nid = $current_node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        }
        break;
      case 'cm_project':
        $nid = $current_node->nid;
        break;
    }
    // Data query
    $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'cm_show');
      $query->propertyCondition('status', 1);
      $query->range(0, 100);
      $query->propertyOrderBy('created', 'DESC');
      $query->fieldCondition('og_group_ref', 'target_id', $nid, '=');
    $result = $query->execute();
    //
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $nodes = entity_load('node', $nids);
      foreach($nodes as $node) {
        // Get field_show_vod thumbnail
        if (isset($node->field_show_vod['und'])) {
          $wrapper = file_stream_wrapper_get_instance_by_uri($node->field_show_vod[LANGUAGE_NONE][0]['uri']);
          $image_uri = $wrapper->getLocalThumbnailPath();
        }
        else {
          if (module_exists('cm_bootstrap_cp_default_images')) {
            $file = cm_bootstrap_cp_default_images_load_image($node->type);
            $image_uri = $file->uri;
          }
        }
        // Strip tags
        $allowable_tags = '';
        if (isset($node->field_description['und'][0]['value'])) {
          $field_description = strip_tags($node->field_description['und'][0]['value'], $allowable_tags);
        }
        else {
          $field_description = '';
        }
        // Build data array for TPL
        $items[$node->nid] = array(
          'nid' => $node->nid,
          'title' => $node->title,
          'description' => cmb_helper_truncate($field_description, $length = 125, array('html' => true, 'ending' => ' . . .', 'exact' => FALSE)),
          'img' => image_style_url('500x281', $image_uri),
        );
      }
      // Send $items array to TPL.
      return theme('cmb_cb_shows_in_series',
        array (
          'content' => $items,
        )
      );
    }
  }
}
