<?php
/**
 * @file
 * prometheus_roles_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function prometheus_roles_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'exclude from message filtering'.
  $permissions['exclude from message filtering'] = array(
    'name' => 'exclude from message filtering',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view error messages'.
  $permissions['view error messages'] = array(
    'name' => 'view error messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view status messages'.
  $permissions['view status messages'] = array(
    'name' => 'view status messages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view warning messages'.
  $permissions['view warning messages'] = array(
    'name' => 'view warning messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'disable_messages',
  );

  return $permissions;
}
