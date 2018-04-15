<?php
function isFibonacci($i) {
    if($i == 0 or $i == 1) return true;
    $current = 1;
    $next = 1;
    while($next < $i) {
        $old = $current;
        $current = $next;
        $next += $old;
        if($next == $i) return true;
    }
    return false;
}

$i = 6765;
echo isFibonacci($i);
?>

