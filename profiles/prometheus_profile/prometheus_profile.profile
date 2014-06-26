<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
if (!function_exists("system_form_install_configure_form_alter")) {
  function system_form_install_configure_form_alter(&$form, $form_state) {
    $form['site_information']['site_name']['#default_value'] = 'Prometheus';
  }
}

/**
 * Implements hook_form_alter().
 *
 * Select the current install profile by default.
 */
if (!function_exists("system_form_install_select_profile_form_alter")) {
  function system_form_install_select_profile_form_alter(&$form, $form_state) {
    foreach ($form['profile'] as $key => $element) {
      $form['profile'][$key]['#value'] = 'prometheus_profile';
    }
  }
}

function prometheus_profile_install_tasks_alter(&$tasks, $install_state) {
  // Replace the install_finished installation task
  $tasks['install_finished']['function'] = 'prometheus_profile_install_finished';
}

// overrides install_finished to revert content feature.
function prometheus_profile_install_finished(&$install_state) {
  drupal_set_title(st('@drupal installation complete', array('@drupal' => drupal_install_profile_distribution_name())), PASS_THROUGH);
  $messages = drupal_set_message();
  $output = '<p>' . st('Congratulations, you installed Prometheus!', array('@drupal' => drupal_install_profile_distribution_name())) . '</p>';
  $output .= '<p>' . (isset($messages['error']) ? st('Review the messages above before visiting <a href="@url">your new site</a>.', array('@url' => url(''))) : st('<a href="@url">Visit your new site</a>.', array('@url' => url('')))) . '</p>';

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the installation profile are registered correctly.
  drupal_flush_all_caches();

  // Remember the profile which was used.
  variable_set('install_profile', drupal_get_profile());

  // Installation profiles are always loaded last
  db_update('system')->fields(array('weight' => 1000))->condition('type', 'module')->condition('name', drupal_get_profile())->execute();

  // Cache a fully-built schema.
  drupal_get_schema(NULL, TRUE);

  // Run cron to populate update status tables (if available) so that users
  // will be warned if they\'ve installed an out of date Drupal version.
  // Will also trigger indexing of profile-supplied content or feeds.
  drupal_cron_run();

  // revert features to ensure they are all installed
  $features = array(
    'prometheus_sample_content_dependencies',
  );
  features_revert($features);
  // ignore any rebuild messages
  node_access_needs_rebuild(FALSE);
  // ignore any other install messages
  drupal_get_messages();

  return $output;
}
