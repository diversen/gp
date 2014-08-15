<?php

class mainTemplate extends template {



/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!doctype html>
<html lang="<?=config::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<!--[if lt IE 9]>
	<script src="http://css3-mediaqueries-js.googlecode.com/svn/trunk/css3-mediaqueries.js"></script>
<![endif]-->
<title><?php echo template_assets::getTitle(); ?></title>

<?php

// set meta refreash
if ( (uri::$info['path'] == '/' || uri::$info['path'] == '/tournament/overview/index') && (!isset($_GET['free'])) && (!isset($_GET['from']) || @$_GET['from'] == 1) ) {
    echo '<meta http-equiv="Refresh" content="120">';
} else {
    //echo "NO refresh";
}

//html::getHeadline($message);
//print_r(uri::$info); print_r($_GET);

template_assets::setRelAsset('css', '//ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/themes/smoothness/jquery-ui.min.css');  
template_assets::setRelAsset('js', '//ajax.googleapis.com/ajax/libs/jquery/2.0.3/jquery.min.js');  
template_assets::setRelAsset('js', '//ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/jquery-ui.min.js');

echo template_assets::getRelAssets();
echo template_assets::getJsHead();
echo template_meta::getMeta();

system_module::setAssets('/templates/gp/dropdown.css');
template_assets::setTemplateCss('gp', null, 10);

// we set touch punch as nested sortable needs this before working on 
// tablets and phones

//template_assets::setJs('/js/jquery.cookie.js');
template_assets::setCss('/templates/gp/devices.css');
template_assets::setJs('/js/jquery.ui.touch-punch.min.js', 0);

//template_assets::setCss('/templates/sharks/devices.css');
echo template_favicon::getFaviconHTML();
echo template_assets::getCompressedCss();
echo template_assets::getInlineCss();


?>
<script>
    // 
// From:
// http://code.stephenmorley.org/javascript/detachable-navigation/ 
// http://code.stephenmorley.org/about-this-site/copyright/
// another solution: 
// http://www.pixelbind.com/make-a-div-stick-when-you-scroll/

/* Handles the page being scrolled by ensuring the navigation is always in
 * view.
 */
function handleScroll(){

  // check that this is a relatively modern browser
  if (window.XMLHttpRequest){

    // determine the distance scrolled down the page
    var offset = window.pageYOffset
               ? window.pageYOffset
               : document.documentElement.scrollTop;

    // set the appropriate class on the navigation
    document.getElementById('gp-block').className =
        (offset > 132 ? 'block fixed' : 'block');

  }

}

// add the scroll event listener
if (window.addEventListener){
  window.addEventListener('scroll', handleScroll, false);
}else{
  window.attachEvent('onscroll', handleScroll);
}

function handleScrollLeft(){

  // check that this is a relatively modern browser
  if (window.XMLHttpRequest){

    // determine the distance scrolled down the page
    var offset = window.pageYOffset
               ? window.pageYOffset
               : document.documentElement.scrollTop;

    // set the appropriate class on the navigation
    document.getElementById('gp-block-left').className =
        (offset > 132 ? 'block_left fixed_left' : 'block_left');

  }

}

// add the scroll event listener
if (window.addEventListener){
  window.addEventListener('scroll', handleScrollLeft, false);
}else{
  window.attachEvent('onscroll', handleScrollLeft);
}

</script>
</head>
<body>
    
    
<?php

moduleloader::includeModule('share');
$share = new share();



if (template::$render == 'basic') {
    return;
}
 
template::geStartHTML()
        
?> 
<div id="page">
    
    
    <div id="sidebar_right">
<?php


$blocks = layout_ext::getBlock('blocks');
foreach ($blocks as  $val){
      echo $val; 
}


?>
   </div>
    <div id="sidebar_left">
        <!--
        <div id="gp-block-left" class="block">
        
        <script language="javascript" type="text/javascript">
   var p = document.location.protocol;
   if (!p || p == null) p = "";
   var s = (p.toLowerCase().indexOf("http") == 0 ? p : "http:") + "//pokerstars.com/en/ad/12084315/120x600.js";
   var r = Math.floor(Math.random()*999999)+''+Math.floor(Math.random()*999999);
   var c = document.createElement("script");
   c.type = "text/javascript";
   c.src = s+"?r="+r;
   c.id = ""+r;
   c.async = true;
   var a = document.getElementsByTagName("script");
   var t = a[a.length-1];
   t.parentNode.insertBefore(c, t);
</script>
<noscript><a target="_blank" href="http://pokerstars.com/en/ad/12084315/120x600free20.gif.click?rq=noscript&vs="><img src="http://pokerstars.com/en/ad/12084315/120x600free20.gif?rq=noscript&vs=" width="120" height="600" alt="" border="0"/></a></noscript>
        
        </div>-->
    </div>
    
    
    <div id="content">
        
        <?php 
    
    if (session::isAdmin()) { 
        echo system_module::getAdminMenu();
    }    

    ?>
    
    <header role="banner">
        <div id="header">
            <?=template::getLogoHTML(); ?>
        </div>
        <?php echo $share->get('grind', array ()); ?>
    </header>
        <nav>
            <div id="main_menu">
<?php

echo layout_ext::getMainMenu();

?>

            </div>
        </nav>
        <nav>
            <div id="module_menu">
<?php

echo layout_ext::getModuleMenu();

?>
            </div>
        </nav>
        <div class="system_message"><p>
<?php

echo session::getActionMessage();

?>
        </p></div>
<?php

// content of loaded module will be printed

}

/**
 * method for print footer of page
 */
public static function printFooter(){
    if (self::$render == 'basic') {
        self::renderEnd();
        return;
    }
    
?>
        <div id="end_content">
<?php

echo template::getEndContent();

?>

        </div>
    </div>
    <div id="footer">
<?php

echo config::getMainIni('footer_message');

?>
 
    </div>
</div>

<?php
    self::renderEnd();
}

    public static function renderEnd () {

echo template::getEndHTML();
echo template_assets::getCompressedJs();
echo template_assets::getInlineJs();

?>
</body>
</html><?php 
    // func end
    }
    
}
