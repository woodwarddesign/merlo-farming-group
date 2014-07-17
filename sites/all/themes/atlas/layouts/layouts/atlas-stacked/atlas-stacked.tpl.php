<section class="panel-main atlas-stacked">
  	   <?php if ($content['top']): ?>
            <div class="panel-top">
              <?php print $content['top']; ?>
            </div>
          <?php else: ?>
        <?php endif; ?>
        <?php if ($content['middle']): ?>
          <div class="panel-middle">
            <?php print $content['middle']; ?>
          </div>
        <?php else: ?>
        <?php endif; ?>
        <?php if ($content['bottom']): ?>
          <div class="panel-bottom">
            <?php print $content['bottom']; ?>
          </div>
        <?php else: ?>
        <?php endif; ?>
</section>
