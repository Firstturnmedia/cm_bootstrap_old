<?php

/**
 * Callback for module settings page.
 */
function cm_bootstrap_custom_blocks_config($form, &$form_state) {
  $form = array();

  $form['cm_bootstrap_custom_blocks']['cmb_latest_shows_production_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sort Video List by Production Date'),
    '#default_value' => variable_get('cmb_latest_shows_production_date', ''),
    '#size' => 120,
  );

  return system_settings_form($form);
}
