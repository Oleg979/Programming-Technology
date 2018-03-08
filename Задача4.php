<?php
function packStr($str) {
    $packed = [];
    for($i=0; $i<strlen($str);$i++) {
        $c = $str[$i]; $len = 1;
        while($str[$i] == $str[$i+1]) {
            $len++; $i++;
        }
        array_push($packed, $len, $str[$i]);
    }
    return $packed;
}

function unpackStr($str) {
    $unpacked = "";
    for($i=0;$i<count($str);$i+=2)
        for($j=0; $j<(int)$str[$i];$j++)
            $unpacked.=$str[$i+1];
    return $unpacked;
}

$str = "wwwwwwwwwwwwwxxghiioooooooooooooooooooooooo";
$packed = packStr($str);
echo implode("",$packed)." ";
$unpacked = unpackStr($packed);
echo $unpacked;
?>
