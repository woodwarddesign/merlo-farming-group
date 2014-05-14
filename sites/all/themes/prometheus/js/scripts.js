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
      equalHeightColumns();
      // unbind click events from toglleMenu function
      $('.menu-link').unbind();
      $('.menuparent > a').unbind();
      //remove toggled class
      $('a').removeClass('toggled');
    }
  }

  fireMobileFunctions();

  $('body').addClass('js');

  // toggle menu

  // the toggle menu doesn't allow the first element to act as a link - it's instead a toggle.
  // the bit below copies the parent link and adds it to the child ul so that the page is accessible
  function addMobileMenuItem() {
    $links = $('li.menuparent').children('a:first-child');
    if ($links.length > 0){
      $links.each(function(i,link) {
        $(link).next().prepend($('<li></li>').append($(link).clone()))
      })
    }
  }

  //remove any items that have been added on resize when going back to desktop width
  function removeMobileMenuItem() {
    $("li.menuparent").each(function() {
       var menuParent = $(this).children('a').text();
       var firstChildItem = $(this).find("ul li:first-child a").text();
       if (menuParent == firstChildItem){
       $(this).find("ul li:first-child").remove();
       }
    });
  }

function equalHeightColumns() {
  if (mobile === 0) {
    var columnHeight = 0;
    var contentHeight = $('#content').outerHeight();
    var sidebarFirstHeight = $('.region-sidebar-first').outerHeight();
    var sidebarSecondHeight = $('.region-sidebar-second').outerHeight();
    if ((contentHeight > sidebarFirstHeight) && (contentHeight > sidebarSecondHeight)) {
      columnHeight = contentHeight;
    }
    else if ((sidebarFirstHeight > contentHeight) && (sidebarFirstHeight > sidebarSecondHeight)) {
      columnHeight = sidebarFirstHeight;
    }
    else if ((sidebarSecondHeight > contentHeight) && (sidebarSecondHeight > sidebarFirstHeight)) {
      columnHeight = sidebarSecondHeight;
    }
    if (columnHeight < $('.view-school-search .view-data').height()) {
     columnHeight = $('.view-school-search .view-data').height() + 50;
    }
    $('.column').height(columnHeight);
  }
  else {
    $('.column').css('height', 'auto');
  }
}

  window.setTimeout(equalHeightColumns, 75);

  function toggleMenu() {
      // add the toggle classes
		  var $menu = $('.region-menu .menu'),
  	  $menulink = $('.menu-link'),
  	  $menuTrigger = $('.menuparent > a');

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

// end custom

  }
};


})(jQuery, Drupal, this, this.document);
