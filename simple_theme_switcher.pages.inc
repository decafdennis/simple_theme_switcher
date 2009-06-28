<?php
// Developed by Dennis Stevense, naquah.net

function simple_theme_switcher_switch($theme) {
  $themes = list_themes();
  $allowed_themes = variable_get('simple_theme_switcher_themes', array());
  if (isset($themes[$theme]) && isset($allowed_themes[$theme]) && $allowed_themes[$theme]) {
    variable_set('theme_default', $theme);
    drupal_set_message(t('The theme has been switched.'));
    drupal_goto('<front>');
  }
  else {
    return drupal_not_found();
  }
}

function simple_theme_switcher_settings() {
  $form = array();
  
  $form['simple_theme_switcher_themes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allowed themes'),
    '#options' => array(),
    '#default_value' => variable_get('simple_theme_switcher_themes', array()),
  );
  foreach (list_themes() as $key => $theme) {
    $form['simple_theme_switcher_themes']['#options'][$key] = $theme->info['name'];
  }
  
  return system_settings_form($form);
}
