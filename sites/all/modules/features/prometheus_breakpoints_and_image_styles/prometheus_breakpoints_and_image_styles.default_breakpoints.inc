<?php
/**
 * @file
 * prometheus_breakpoints_and_image_styles.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function prometheus_breakpoints_and_image_styles_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.atlas.desk';
  $breakpoint->name = 'desk';
  $breakpoint->breakpoint = '(min-width: 960px)';
  $breakpoint->source = 'atlas';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.atlas.desk'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.atlas.mobile';
  $breakpoint->name = 'mobile';
  $breakpoint->breakpoint = '(min-width: 0px)';
  $breakpoint->source = 'atlas';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.atlas.mobile'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.atlas.tablet';
  $breakpoint->name = 'tablet';
  $breakpoint->breakpoint = '(min-width: 640px)';
  $breakpoint->source = 'atlas';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.atlas.tablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.desk';
  $breakpoint->name = 'desk';
  $breakpoint->breakpoint = '(min-width: 960px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.desk'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.mobile';
  $breakpoint->name = 'mobile';
  $breakpoint->breakpoint = '(min-width: 0px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.mobile'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'custom.user.tablet';
  $breakpoint->name = 'tablet';
  $breakpoint->breakpoint = '(min-width: 640px)';
  $breakpoint->source = 'user';
  $breakpoint->source_type = 'custom';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['custom.user.tablet'] = $breakpoint;

  return $export;
}
