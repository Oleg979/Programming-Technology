<?
function parse($str) {
        $tokens = [];
        $buf = "";
        for($i=0;$i<strlen($str);$i++) {
            if(is_numeric($str[$i])) 
                $buf.=$str[$i];
            else switch($str[$i]) {
                case '+':
                case '-':
                    array_push($tokens,$buf);
                    $buf="";
                    array_push($tokens, $str[$i]);
                    break;
            }
        }
        array_push($tokens,$buf);
        return $tokens;
}

function calc($tokens) {
    $res = $tokens[0];
    for($i=1;$i<count($tokens);$i+=2) {
        if($tokens[$i]=="+") $res+=$tokens[$i+1];
        else $res-=$tokens[$i+1];
    }
    return $res;
}

$str = "-33+22+11";
$tokens = parse($str);
$res = calc($tokens);
echo $res;
?>
