/**
 * @file
 * JavaScript file for the Atlas
 *
 */

(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

  // start custom

  $(document).ready(function() {

  //set up variable for mobile. set this to keep track of width so functions are run only on transition from
  // moble to desktop and vice versa. if this isn't done, functions will fire constantly as window is resized
  var mobile = 0;
  // keeps track if function has been run
  var functionStatus = 0;

  function setMobileValue() {
    var viewport = $(window).width();
    if (viewport < 970) {
      mobile = 1;
    }
    else {
      mobile = 0;
    }
  }

  setMobileValue();

  // determine if width is 'mobile' and if function has already been run
  function fireMobileFunctions() {
    if (mobile === 1 && functionStatus == 0) {
      // turn this 'on' so that it doesn't run multiple times during resize
      functionStatus = 1;
      addMobileMenuItem();
      toggleMenu();
      equalHeightColumns();
    }
    else if (mobile === 0 && functionStatus == 1)  {
      //turn 'off' so that it will run again if resized to mobile
      functionStatus = 0;
      removeMobileMenuItem();
      // unbind click events from toglleMenu function
      $('.menu-link').unbind();
      $('.expanded > a').unbind();
      //remove toggled class
      $('a').removeClass('toggled');
    }
  }

  fireMobileFunctions();

  $('body').removeClass('no-js');
  $('body').addClass('js');

  // toggle menu

  // the toggle menu doesn't allow the first element to act as a link - it's instead a toggle.
  // the bit below copies the parent link and adds it to the child ul so that the page is accessible
  function addMobileMenuItem() {
    $links = $('li.expanded').children('a:first-child');
    if ($links.length > 0){
      $links.each(function(i,link) {
        $(link).next().prepend($('<li></li>').append($(link).clone()))
      })
    }
  }

  //remove any items that have been added on resize when going back to desktop width
  function removeMobileMenuItem() {
    $("li.expanded").each(function() {
       var menuParent = $(this).children('a').text();
       var firstChildItem = $(this).find("ul li:first-child a").text();
       if (menuParent == firstChildItem){
       $(this).find("ul li:first-child").remove();
       }
    });
  }

  function toggleMenu() {
      // add the toggle classes
		  var $menu = $('.menu-block-1 > .main-menu-1'),
  	  $menulink = $('.menu-link'),
  	  $menuTrigger = $('.expanded > a');

  		$menulink.click(function(e) {
  			e.preventDefault();
  			$menulink.toggleClass('toggled');
  			$menu.toggleClass('toggled');
  		});

  		$menuTrigger.click(function(e) {
  			e.preventDefault();
  			var $this = $(this);
  			$this.toggleClass('toggled').next('ul').toggleClass('toggled');
  		});
  }

    $(window).resize(function() {
      setMobileValue();
      fireMobileFunctions();
    });

		});

    function is_touch_device() {
     return (('ontouchstart' in window)
          || (navigator.MaxTouchPoints > 0)
          || (navigator.msMaxTouchPoints > 0));
    }
    // remove add classes as needed
    if (is_touch_device()) {
       $('body').removeClass('no-touch');
       $('body').addClass('touch');
    }

// end custom

  }
};


})(jQuery, Drupal, this, this.document);
