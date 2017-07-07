(function($) {

  Drupal.behaviors.cmb_jumbotron__slider = {
    attach: function (context, settings) {

      $(window).load(function() {
        $('.cc-cmb-jumbotron .flexslider').flexslider({
          animation: "slide",
          controlNav: false,
          slideshow: true,
          start: function(slider) {
            $.flexloader(slider);
          },
          after: function(slider) {
            $.flexloader(slider);
          }
        });
      });

    }
  };

})(jQuery);
