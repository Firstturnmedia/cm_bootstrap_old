<section class="content-component cc--image <?php print $image['fw_class']; ?>">
  <div class="row">
    <div class="col-md-12">
      <?php if ($image['link']): ?>
        <?php if ($image['img_src']): ?>
          <a target="<?php print $image['link']['target']; ?>" href="<?php print $image['link']['href']; ?>">
            <img class="img-responsive" src="<?php print $image['img_src']; ?>"/>
          </a>
        <?php endif; ?>
      <?php else: ?>
        <?php if ($image['img_src']): ?>
          <img class="img-responsive" src="<?php print $image['img_src']; ?>"/>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  </div>
</section>
