<?php
/**
 * @file
 * prometheus_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function prometheus_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-categories.
  $menus['menu-categories'] = array(
    'menu_name' => 'menu-categories',
    'title' => 'Categories',
    'description' => 'Contains blog categories',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Categories');
  t('Contains blog categories');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
