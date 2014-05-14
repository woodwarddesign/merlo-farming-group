/**
 * @file
 * JavaScript file for the theme.
 *
 */

(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

    // User profile form - set password indicator color based on content value

      jQuery( ".password-field" ).one("keypress", function () {
        setInterval(function () {
        var str = jQuery( ".password-strength-text" ).text();
            if (str == "Weak") {
                  jQuery( ".password-strength .password-indicator div" ).css('background', '#f76558');
          }
          else if (str == "Fair") {
              jQuery( ".password-strength .password-indicator div" ).css('background', '#f7d354');
          }
          else  jQuery( ".password-strength .password-indicator div" ).css('background', '#b0dd91');
    }, 300);

      });

  }
};


})(jQuery, Drupal, this, this.document);
