<?php
function isValid($str) {
    $stack = [];
    for($i=0;$i<strlen($str);$i++) {
        if($str[$i]=="{" or $str[$i]=="[" or $str[$i]=="(" ) 
            array_push($stack, $str[$i]);
        else if($str[$i]=="}" and array_pop($stack) != "{")
                return false;
        else if($str[$i]==")" and array_pop($stack) != "(")
                return false;
        else if($str[$i]=="]" and array_pop($stack) != "[")
                return false;
    }
    if(count($stack)!=0) return false;
    return true;
}

$str = "{((abc[ch]e)ckke{ss}k{ds})";
echo isValid($str);
?>
