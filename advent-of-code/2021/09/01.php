<?

$ans = 0;
$v = [];
$len = 0;
foreach (file('input.txt') as $line) {
  $s = trim($line);
  $len = strlen($s);
  $vv = [];
  for ($i = 0; $i < $len; $i++) $vv[] = (int)$s[$i];
  $v[] = $vv;
}

for ($i = 0; $i < count($v); $i++) {
  for ($j = 0; $j < $len; $j++) {
    if (
      ($i == 0 || $v[$i][$j] < $v[$i - 1][$j]) &&
      ($i >= count($v) - 1 || $v[$i][$j] < $v[$i + 1][$j]) &&
      ($j == 0 || $v[$i][$j] < $v[$i][$j - 1]) &&
      ($j >= $len - 1 || $v[$i][$j] < $v[$i][$j + 1])
    ) {
      echo "Low {$v[$i][$j]}\n";
      $ans += (int)$v[$i][$j] + 1;
    }
  }
}

echo "$ans\n";
