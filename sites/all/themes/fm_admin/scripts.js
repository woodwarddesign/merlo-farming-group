(function ($, Drupal) {
$(document).ready(function() {
  target = jQuery("select#edit-field-commodity-type-und");
  crop = "";
  jQuery(target).on('change', function() {
    crop = jQuery(this).val();
  switch (crop) {
    case "almonds" :
      jQuery( ".walnut-variety, .rice-variety" ).css('display', 'none');
      jQuery( ".almond-variety" ).css('display', 'block');
    break;
  case "walnuts" :
      jQuery( ".almond-variety, .rice-variety" ).css('display', 'none');
      jQuery( ".walnut-variety" ).css('display', 'block');
    break;
  case "rice" :
      jQuery( ".almond-variety, .walnut-variety" ).css('display', 'none');
      jQuery( ".rice-variety" ).css('display', 'block');
    break;
  default :
  jQuery( ".almond-variety, .rice-variety, walnut-variety" ).css('display', 'none');
  }
  });
});
})(jQuery, Drupal);
