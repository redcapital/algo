<?

$ans = 0;
$v = [];
$memp = [];
$m = [];
$len = 0;
foreach (file('input.txt') as $line) {
  $s = trim($line);
  $len = strlen($s);
  $vv = [];
  for ($i = 0; $i < $len; $i++) {
    $vv[] = (int)$s[$i];
  }
  $v[] = $vv;
}

function fill($x, $y) {
  global $v, $m, $len;
  $m[$x][$y] = true;
  $res = 1;
  if ($x - 1 >= 0 && !$m[$x - 1][$y] && $v[$x - 1][$y] < 9) {
    $res += fill($x - 1, $y);
  }
  if ($x + 1 < count($v) && !$m[$x + 1][$y] && $v[$x + 1][$y] < 9) {
    $res += fill($x + 1, $y);
  }
  if ($y + 1 < $len && !$m[$x][$y + 1] && $v[$x][$y + 1] < 9) {
    $res += fill($x, $y + 1);
  }
  if ($y - 1 >= 0 && !$m[$x][$y - 1] && $v[$x][$y - 1] < 9) {
    $res += fill($x, $y - 1);
  }
  return $res;
}

for ($i = 0; $i < count($v); $i++) {
  $zzz = [];
  for ($j = 0; $j < $len; $j++) $zzz[] = false;
  $memp[] = $zzz;
}

$ans = 1;
$sz = [];
for ($i = 0; $i < count($v); $i++) {
  for ($j = 0; $j < $len; $j++) {
    if (
      ($i == 0 || $v[$i][$j] < $v[$i - 1][$j]) &&
      ($i >= count($v) - 1 || $v[$i][$j] < $v[$i + 1][$j]) &&
      ($j == 0 || $v[$i][$j] < $v[$i][$j - 1]) &&
      ($j >= $len - 1 || $v[$i][$j] < $v[$i][$j + 1])
    ) {
      $m = $memp;
      //echo "Low {$v[$i][$j]}\n";
      //echo "sz " . fill($i, $j) . "\n";
      $sz[] = fill($i, $j);
    }
  }
}

sort($sz);
$szz = count($sz);
$ans = $sz[$szz - 2] * $sz[$szz - 1] * $sz[$szz - 3];

echo "$ans\n";
