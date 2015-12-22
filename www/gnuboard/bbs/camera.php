<meta http-equiv="Content-Type" content="text/html;charset=utf-8">
<?php
include_once("./_common.php");
include_once("./_head.php");

$host = $_SERVER['HTTP_HOST'];
$camport = 9090;
if($member['mb_level'] != 10)
{
?>
	<font size = 5 color = red>관리자로 로그인 하시기 바랍니다.</font>
<?
}
else{
?>
<center><font size = 5>내부 CCTV 입니다 </font></center>

<img alt="" src = "http://<?=$host?>:<?=$camport?>/?action=stream" width="640" height = "480" />

<?
}

include_once(G5_PATH.'/_tail.php');
?>
