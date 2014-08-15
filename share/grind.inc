<?php

$url = config::getSchemeWithServerName();
//$url.= $vars['return_url'];

//$meta = template_meta::getMeta();
//print_r($meta);
//die;

$url = rawurlencode($url);
$subject = rawurlencode(config::getMainIni('meta_title'));
$abstract = rawurlencode(config::getMainIni('meta_desc'));



if (empty($abstract)) {
    $abstract = $subject;
}

echo '<div id="share_buttons">';

$options = array ('height' => '29', 'width' => '28', 'alt' => 'fb-img');
$fb_href = "http://www.facebook.com/sharer.php?u=$url&amp;t=$abstract";

echo html::createHrefImage($fb_href, '/templates/gp/assets/front/fblogo.png', $options);
echo "&nbsp;";
$tw_href = "http://twitter.com/share?url=$url&amp;text=$abstract";
echo html::createHrefImage($tw_href, '/templates/gp/assets/front/twitlogo.png', array ('alt' => 'twitter-img'));
echo "&nbsp;";
$g_href = "https://plus.google.com/share?url=$url";
echo html::createHrefImage($g_href, '/templates/gp/assets/front/googlelogo.png', array ('alt' => 'google-plus-img'));
echo '</div>';
return;

?>

            

            <a href="http://www.facebook.com/sharer.php?u=<?=$url?>&t=<?=$abstract?>">Facebook</a>.
            <a href="https://plus.google.com/share?url=<?=$url?>">Google+</a>,
            <a href="http://twitter.com/share?url=<?=$url?>&amp;text=<?=$abstract?>">Twitter</a>,
            
