<?php

/**
 * Implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Atlas stacked'),
  'category' => t('Columns: 1'),
  'icon' => 'icon.png',
  'theme' => 'atlas-stacked',
  'css' => 'css/panels-layouts/stacked.css',
  'regions' => array(
  'top' => t('Top Content'),
  'middle' => t('Middle Content'),
  'bottom' => t('Bottom Content'),
  ),
);
