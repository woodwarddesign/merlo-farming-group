<?php
/**
 * @file
 * prometheus_boxes_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function prometheus_boxes_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_blocks';
  $context->description = 'Place blocks on blog, taxonomy pages';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog*' => 'blog*',
        'tags*' => 'tags*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-categories' => array(
          'module' => 'menu',
          'delta' => 'menu-categories',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Place blocks on blog, taxonomy pages');
  $export['blog_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'contact_page_block';
  $context->description = 'Location of contact page message';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-contact_form_message' => array(
          'module' => 'boxes',
          'delta' => 'contact_form_message',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Location of contact page message');
  $export['contact_page_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'getting_started_block';
  $context->description = 'Location of the Getting Started block';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-prometheus_front_box' => array(
          'module' => 'boxes',
          'delta' => 'prometheus_front_box',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Location of the Getting Started block');
  $export['getting_started_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sample_content_block';
  $context->description = 'Location of login block - just filler to demonstrate layout';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blog/diam-facilisi-meus-olim' => 'blog/diam-facilisi-meus-olim',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Location of login block - just filler to demonstrate layout');
  $export['sample_content_block'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_block_locations';
  $context->description = 'Block locations';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block locations');
  t('Blocks');
  $export['sitewide_block_locations'] = $context;

  return $export;
}
