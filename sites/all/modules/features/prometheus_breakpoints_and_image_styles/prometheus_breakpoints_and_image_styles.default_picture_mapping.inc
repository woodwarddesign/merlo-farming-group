<?php
/**
 * @file
 * prometheus_breakpoints_and_image_styles.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function prometheus_breakpoints_and_image_styles_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'blog_post_image';
  $picture_mapping->breakpoint_group = 'blog_post_image';
  $picture_mapping->mapping = array(
    'custom.user.mobile' => array(
      '1x' => 'blog_post_mobile',
    ),
    'custom.user.tablet' => array(
      '1x' => 'blog_post_tablet',
    ),
    'custom.user.desk' => array(
      '1x' => 'blog_post',
    ),
  );
  $export['blog_post_image'] = $picture_mapping;

  return $export;
}
