<?

// 404 too low
// 606 too high
// 407 too low

$lines = file('input.txt');

$valid = 0;

foreach ($lines as $line) {
  sscanf($line, "%d-%d %c: %s", $lo, $hi, $c, $s);
  $lo--;
  $hi--;
  $v1 = isset($s[$lo]) && $s[$lo] == $c;
  $v2 = isset($s[$hi]) && $s[$hi] == $c;
  if ($v1 != $v2) {
    echo $line;
    $valid++;
  }
}

echo "$valid\n";
