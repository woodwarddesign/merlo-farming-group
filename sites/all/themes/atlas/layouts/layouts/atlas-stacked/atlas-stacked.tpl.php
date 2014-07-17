<section class="panel-main atlas-stacked">
  	   <?php if ($content['top']): ?>
            <section class="panel-top">
              <?php print $content['top']; ?>
            </section>
          <?php else: ?>
        <?php endif; ?>
        <?php if ($content['middle']): ?>
          <section class="panel-middle">
            <?php print $content['middle']; ?>
          </section>
        <?php else: ?>
        <?php endif; ?>
        <?php if ($content['bottom']): ?>
          <section class="panel-bottom">
            <?php print $content['bottom']; ?>
          </section>
        <?php else: ?>
        <?php endif; ?>
</section>
