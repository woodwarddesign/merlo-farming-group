<?php
/**
 * @file
 * prometheus_roles_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function prometheus_roles_permissions_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 10,
  );

  return $roles;
}
