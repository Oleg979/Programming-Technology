ini_set("memory_limit","580M");
<?php
function addOne($str,$pos) {
    $res = $str;
    $res[$pos] = '1';
    return $res;
}

function generate($n) {
    global $res;
    for($i=0;$i<$n; $i++) $tmp .= '0';
    array_push($res,$tmp);
    for($i=0;$i<$n;$i++) {
        array_push($res,addOne($tmp,$i));
        fill($i,$res[count($res)-1]);
    }
    return $res;
}

function fill($pos, $str) {
    global $res,$n;
    for($j=$pos+2;$j<$n;$j++) {
        array_push($res,addOne($str,$j));
        fill($j,$res[count($res)-1]);
    }
}

$n = 7; $res = [];
print_r(generate($n));
?>
