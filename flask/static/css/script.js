
$('.effect').on('inview', function() {
	 var $item = $(this);
	 $item.addClass('start');
});


$(function(){
$('a[href^=#]').click(function(){
var speed = 500;
var href= $(this).attr("href");
var target = $(href == "#" || href == "" ? 'html' : href);
var position = target.offset().top;
$("html, body").animate({scrollTop:position}, speed, "swing");
return false;
});
});

//トップへ戻るボタン
$(function() {
    var topBtn = $('#to_top');   
    topBtn.hide();
    //スクロールが100に達したらボタン表示
    $(window).scroll(function () {
        if ($(this).scrollTop() > 100) {
            topBtn.fadeIn();
        } else {
            topBtn.fadeOut();
        }
    });
});

//スマホメニュー
var bnrBtn = $('#g_navi');
var bnrBtn2 = $('#h_box_sp');
var menuOpen = false;
var scrollpos;

$('.bg_bl').hide();

var ttt = false;

$(function(){
        $(".menu_btn").on("click", function() {
	if(ttt == false) {
          bnrBtn.fadeIn();
		  bnrBtn2.fadeIn();
          menuOpen = true;
		  $('.om').hide();
		  $('.bg_bl').fadeIn();
		  scrollpos = $(window).scrollTop();
      $('body').addClass('fixed').css({'top': -scrollpos});
	        $(".menu_btn").addClass('opened');
	  ttt = true;
	} else {
		bnrBtn.fadeOut();
		  bnrBtn2.fadeOut();
          menuOpen = false;
		  $('.om').show();
		  $('.bg_bl').fadeOut();
		  $('body').removeClass('fixed').css({'top': 0});
		  $(".menu_btn").removeClass('opened');
      window.scrollTo( 0 , scrollpos );
	  ttt = false;
	}
        });
});

$('#g_navi a[href]').on('click', function(event) {
	if(ttt == true) {
    $('.menu_btn').trigger('click');
	}
});

	 
$(window).resize(function(){
    var w = $(window).width();
    var x = 1100;
    if (w >= x) {
		bnrBtn.fadeIn();
		bnrBtn2.fadeIn();
        menuOpen = false;
		$('.bg_bl').hide();
		ttt = false;
		$(".menu_btn").removeClass('opened');
    } else if (ttt == false) {
		bnrBtn.fadeOut();
		bnrBtn2.fadeOut();
	}
});

//画像切替
$(function() {

  var $elem = $('.img-switch');
  var sp = '_sp.';
  var pc = '_pc.';
  var replaceWidth = 960;

  function imageSwitch() {
    var windowWidth = parseInt($(window).width());
    $elem.each(function() {
      var $this = $(this);
      if(windowWidth >= replaceWidth) {
        $this.attr('src', $this.attr('src').replace(sp, pc));
      } else {
        $this.attr('src', $this.attr('src').replace(pc, sp));
      }
    });
  }
  imageSwitch();

  var resizeTimer;
  $(window).on('resize', function() {
    clearTimeout(resizeTimer);
    resizeTimer = setTimeout(function() {
      imageSwitch();
    }, 200);
  });
});

//アコーディオン
$(function(){
        $(".ac_menu").on("click", function() {
            $(this).next().slideToggle(); 
            $(this).toggleClass("active"); 
        });
});

/*$(function() {
  
var nav    = $('#g_navi'),
    offset = nav.offset();
  
$(window).scroll(function () {
  if($(window).scrollTop() > offset.top) {
    nav.addClass('nav_fixed');
  } else {
    nav.removeClass('nav_fixed');
  }
});
$(window).resize(function(){
	offset = nav.offset();
 }); 
});*/

window.onload = function() {

$(function() {
  var $win = $(window),
      $main = $('main'),
      $nav = $('#g_navi'),
      navHeight = $nav.outerHeight(),
      navPos = $nav.offset().top,
      fixedClass = 'nav_fixed';

  $win.on('load scroll', function() {
    var value = $(this).scrollTop();
    if ( value > navPos ) {
      $nav.addClass(fixedClass);
//     $main.css('margin-top', navHeight);
    } else {
      $nav.removeClass(fixedClass);
//      $main.css('margin-top', '0');
    }
  });
  
  $win.on('resize', function() {
	  navPos = $nav.offset().top;
  });
  
});



}