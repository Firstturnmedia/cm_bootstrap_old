<?php

function _cb_pd_p_all_series() {
  // Get current nid
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node');
      $query->entityCondition('bundle', 'cm_project');
      $query->propertyCondition('status', 1);
      $query->fieldCondition('field_partner', 'target_id', $nid, '=');
      $query->propertyOrderBy('created', 'DESC');
      $result = $query->execute();
      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = entity_load('node', $nids);
        //dpm($nodes);
        foreach ($nodes as $node) {
          // Series img
          // Get image from field_series_image
          if (isset($node->field_series_image['und'])) {
            $image_uri = $node->field_series_image['und'][0]['uri'];
            $image_src = image_style_url('500x281', $image_uri);
          }
          // Else, no image, use default image.
          else {
            if (module_exists('cm_bootstrap_cp_default_images')) {
              $file = cm_bootstrap_cp_default_images_load_image($node->type);
              if ($file) {
                $image_uri = $file->uri;
                $image_src = image_style_url('500x281', $image_uri);
              }
              else {
                $image_src = "data:image/svg+xml;charset=utf-8,<svg%20xmlns%3D'http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg'%20width%3D'1440'%20height%3D'720'><rect%20width%3D'100%25'%20height%3D'100%25'%20fill%3D'whitesmoke'%2F><%2Fsvg>";
              }
            }
          }
          // Build items array for use in TPL.
          $items[$node->nid] = array(
            'nid' => $node->nid,
            'title' => $node->title,
            'series_img' => $image_src,
          );
        }
        //dpm($items);
        // Send $items array to TPL.
        return theme('cb_pd_p_all_series',
          array (
            'content' => $items,
          )
        );
      }
  }




  //return '_cb_pd_p_all_series';
}
