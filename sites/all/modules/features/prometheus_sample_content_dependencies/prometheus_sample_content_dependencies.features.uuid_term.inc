<?php
/**
 * @file
 * prometheus_sample_content_dependencies.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function prometheus_sample_content_dependencies_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Category 4',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '23f04d86-8241-413e-9eca-7ab63800b5fd',
    'vocabulary_machine_name' => 'tags',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'tags/category-4',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Category 2',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'e6cbc0ee-7bb8-48c5-9f02-2c727a99b826',
    'vocabulary_machine_name' => 'tags',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'tags/category-2',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Category 3',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'f3301e65-6910-4d46-9ea0-1bdc7d7bbee3',
    'vocabulary_machine_name' => 'tags',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'tags/category-3',
        'language' => 'und',
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Category 1',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => 'fca3dad1-b218-42f0-a835-3af7a103f983',
    'vocabulary_machine_name' => 'tags',
    'metatags' => array(),
    'url_alias' => array(
      0 => array(
        'alias' => 'tags/category-1',
        'language' => 'und',
      ),
    ),
  );
  return $terms;
}
