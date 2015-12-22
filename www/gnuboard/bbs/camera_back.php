<?php
include_once('./_common.php');
include_once(G5_EDITOR_LIB);

//$referer = parse_url($_SERVER['HTTP_REFERER']);
//$myip = $referer[host];
$referer = $_SERVER['HTTP_HOST'];
$camport = 9090;

?>

<img alt = "" src = "http://<?= $referer ?>:<?=$camport?>/?action=stream" width = "640" height = "480" />


<br><br> Cam Server IP : <?= $referer ?>:<?=$camport?>
<br>Session Level <?=$member['mb_id']?>






