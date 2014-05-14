<?php

/*  Implements hook_form_FORM_ID_alter  */

function responsive_starter_form_install_configure_form_alter(&$form, $form_state) {
  // Add profile as site name.
  $form['site_information']['site_name']['#default_value'] = 'Prometheus';
	//On submit, execute foundation_profile_install function
	$form['#submit'][] = '_responsive_starter_profile_install_configure_form_submit';
}

function _responsive_starter_profile_install_configure_form_submit($form, &$form_state) {
	
	// Everything below this line of function from original function in core ...
	variable_set('site_name', $form_state['values']['site_name']);
  variable_set('site_mail', $form_state['values']['site_mail']);
  variable_set('date_default_timezone', $form_state['values']['date_default_timezone']);
  variable_set('site_default_country', $form_state['values']['site_default_country']);

  //Set the default front page
  variable_set('site_frontpage', 'lorem-ipsum-dolor');
	
	// Enable update.module if this option was selected.
  if ($form_state['values']['update_status_module'][1]) {
    module_enable(array('update'), FALSE);

    // Add the site maintenance account's email address to the list of
    // addresses to be notified when updates are available, if selected.
    if ($form_state['values']['update_status_module'][2]) {
      variable_set('update_notify_emails', array($form_state['values']['account']['mail']));
    }
  }

  // We precreated user 1 with placeholder values. Let's save the real values.
  $account = user_load(1);
  $merge_data = array('init' => $form_state['values']['account']['mail'], 'roles' => !empty($account->roles) ? $account->roles : array(), 'status' => 1, 'timezone' => $form_state['values']['date_default_timezone']);
  user_save($account, array_merge($form_state['values']['account'], $merge_data));
  // Load global $user and perform final login tasks.
  $user = user_load(1);
  user_login_finalize();

  if (isset($form_state['values']['clean_url'])) {
    variable_set('clean_url', $form_state['values']['clean_url']);
  }

  // Record when this install ran.
  variable_set('install_time', $_SERVER['REQUEST_TIME']);
}

/** Implements hook_install_tasks_alter()
*   There is an issue with profile status being set to 0 in system table, causing error message on admin pages 
*   Custom function corrects this issue.
*/

function responsive_starter_install_tasks_alter(&$tasks, $install_state) {
  // Replace the install_finished installation task 
  $tasks['install_finished']['function'] = 'responsive_starter_install_finished';
}

function responsive_starter_install_finished(&$install_state) {
  drupal_set_title(st('@drupal installation complete', array('@drupal' => drupal_install_profile_distribution_name())), PASS_THROUGH);
  $messages = drupal_set_message();
  $output = '<p>' . st('Congratulations, you installed the Prometheus Responsive Starter Kit!', array('@drupal' => drupal_install_profile_distribution_name())) . '</p>';
  $output .= '<p>' . (isset($messages['error']) ? st('Review the messages above before visiting <a href="@url">your new site</a>.', array('@url' => url(''))) : st('<a href="@url">Visit your new site</a>.', array('@url' => url('')))) . '</p>';

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the install profile are registered correctly.
	
	// foundation profile breaks if this is run
  //drupal_flush_all_caches();

  // Remember the profile which was used.
  variable_set('install_profile', drupal_get_profile());

  // Install profiles are always loaded last
	// The update below is an edit to fix the error message related to the profile after installation
  db_update('system')
    ->fields(array('weight' => 1000, 'status' => 1, 'schema_version' => 0))
    ->condition('type', 'module')
    ->condition('name', 'responsive_starter')
    ->execute();
		
  db_update('system')
    ->fields(array('status' => 0))
    ->condition('type', 'module')
    ->condition('name', 'standard')
    ->execute();

  // Cache a fully-built schema.
  drupal_get_schema(NULL, TRUE);

  // Run cron to populate update status tables (if available) so that users
  // will be warned if they've installed an out of date Drupal version.
  // Will also trigger indexing of profile-supplied content or feeds.
  drupal_cron_run();

  return $output;
}