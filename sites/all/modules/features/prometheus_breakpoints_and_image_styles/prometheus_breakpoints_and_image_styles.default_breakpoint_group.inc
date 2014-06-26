<?php
/**
 * @file
 * prometheus_breakpoints_and_image_styles.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function prometheus_breakpoints_and_image_styles_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.atlas.mobile';
  $breakpoints[] = 'breakpoints.theme.atlas.tablet';
  $breakpoints[] = 'breakpoints.theme.atlas.desk';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'atlas';
  $breakpoint_group->name = 'Atlas';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['atlas'] = $breakpoint_group;

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'custom.user.mobile';
  $breakpoints[] = 'custom.user.tablet';
  $breakpoints[] = 'custom.user.desk';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'blog_post_image';
  $breakpoint_group->name = 'Blog post image';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['blog_post_image'] = $breakpoint_group;

  return $export;
}
