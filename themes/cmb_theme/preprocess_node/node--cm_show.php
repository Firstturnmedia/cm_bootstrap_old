<?php

function _node__cm_show(&$variables) {
  $node = $variables['node'];

  $data = [
    'nid' => $node->nid,
    'title' => $node->title,
  ];

  $debug = $data;

  $variables['cm_show'] = $data;
}
