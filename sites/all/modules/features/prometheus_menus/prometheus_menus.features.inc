<?php
/**
 * @file
 * prometheus_menus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function prometheus_menus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
