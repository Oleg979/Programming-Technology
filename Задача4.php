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
echo "Исходная строка: ".$str."<br>";
$packed = packStr($str);
echo "Упакованная строка: ".implode("",$packed)."<br>";
$unpacked = unpackStr($packed);
echo "Распакованная строка: ".$unpacked."<br>";
?>
