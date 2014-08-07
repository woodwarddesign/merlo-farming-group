/**
 * @file
 * JavaScript file for Atlas theme
 *
 */

(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.my_custom_behavior = {
  attach: function(context, settings) {

  // start custom

  $(document).ready(function() {

  // weather data from forecat.io. First see if there is recent data stored locally.
  if (localStorage.d1 === undefined) {
    getWeather();
  }
  else {
    var d1 = Date.parse(localStorage.d1);
    var d2 = new Date();
    var dateDiff = d2 - d1;

    // if this is true, weather is over 15 minutes old and should be retrieved again
    if (dateDiff > 900000) {
      localStorage.clear();
      getWeather();
    }
    else {
      addWeatherWidget();
    }
  }

  function getWeather() {
    $.ajax({
        url: 'https://api.forecast.io/forecast/1c11c79d6b408b1165bf09c2337b0f4c/39.625379,-121.799302',
        dataType: 'jsonp',
        success: function(data){
          localStorage.d1 = new Date();
          localStorage.temp = parseInt(Math.round(data.currently.temperature));
          localStorage.feelsLike = parseInt(Math.round(data.currently.apparentTemperature));
          localStorage.humidity = (parseInt(data.currently.humidity * 100));
          localStorage.precipProbability = (parseInt(data.currently.precipProbability * 100));
          localStorage.icon = data.currently.icon;
          localStorage.forecastHigh = parseInt(Math.round(data.daily.data[0].temperatureMax));
          localStorage.forecastLow = parseInt(Math.round(data.daily.data[0].temperatureMin));
          localStorage.weatherSummary = data.currently.summary;
          addWeatherWidget();
        },
        error: function() {
          $('.front .weather-widget').append('<h2 class="pane-title">Current Weather</h2>' + '<p>Weather is temporarily unavailable.</p>');
        }
    });
  }

  function addWeatherWidget() {
    // remove placeholder text
    $('.remove-me').remove();
    // add weather data
    $('.front .weather-widget').append('<div class="widget-wrapper ' + localStorage.icon + '-top"><div class="weather-bg ' + localStorage.icon + '"></div><div class="weather-widget-top">' + '<p class="current-summary grid-2-3 first"><span class="forecast-high">High: ' + localStorage.forecastHigh + '</span><span class="forecast-low">Low: ' + localStorage.forecastLow + '</span><span class="feels-like">Feels like: ' + localStorage.feelsLike + '</span></p>' + '<p class="current-temp grid-1-3 last"><span class="temp">' + localStorage.temp + '&deg;</span><span class="text-summary">' + localStorage.weatherSummary + '</span></p></div><div class="weather-widget-bottom"><p class="humidity-precip grid-1-2 first">Humidity: '  + localStorage.humidity  + '%</p>' + '<p class="grid-1-2 last">Durham, CA</p></div></div>');
  }

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
    $('li.expanded').each(function() {
       var menuParent = $(this).children('a').text();
       var firstChildItem = $(this).find('ul li:first-child a').text();
       if (menuParent == firstChildItem){
       $(this).find('ul li:first-child').remove();
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

    // add placeholder image to google news feed item
    var placeholderImage = '<img src=\'/sites/all/themes/atlas/images/news-filller-image.png\' alt=\'News placeholder image\'>';
    $( '.view-google-news-feed td:first-child').not(':has(span a img)').append(placeholderImage);

// end custom

  }
};


})(jQuery, Drupal, this, this.document);
