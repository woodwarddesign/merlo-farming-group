<?php
/**
 * @file
 * prometheus_boxes_context.box.inc
 */

/**
 * Implements hook_default_box().
 */
function prometheus_boxes_context_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'contact_form_message';
  $box->plugin_key = 'simple';
  $box->title = 'Before You Fill that Out...';
  $box->description = 'Contact form message';
  $box->options = array(
    'body' => array(
      'value' => '<p>You should know this demo form doesn\'t send messages to a real email address.</p>
',
      'format' => 'full_html',
    ),
  );
  $export['contact_form_message'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'prometheus_front_box';
  $box->plugin_key = 'simple';
  $box->title = 'Tips to Get Started';
  $box->description = 'A box for the front page of the Prometheus installation profile.';
  $box->options = array(
    'body' => array(
      'value' => '<img alt="Sample pic" height="225" src="/sites/default/files/john-doe_0.jpg" width="350">
<p>Once Prometheus is stabilized, more thorough documentation will be written. Until then, the brief write up here will have to suffice. You can also visit the project page on <a href="https://github.com/friendlymachine/prometheus">GitHub</a> to open an issue or contact me.</p>',
      'format' => 'advanced_full_html',
    ),
  );
  $export['prometheus_front_box'] = $box;

  return $export;
}
