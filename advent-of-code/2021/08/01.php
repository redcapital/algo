<?

$ans = 0;
foreach (file('input.txt') as $line) {
  $s = trim($line);
  list($words, $d) = explode(' | ', $s);
  foreach (explode(' ', $d) as $word) {
    $dist = 0;
    $m = [];
    for ($i = 0; $i < strlen($word); $i++) {
      $m[$word[$i]] = true;
    }
    $dist = count($m);
    if ($dist == 2 || $dist == 4 || $dist == 3 || $dist == 7) {
      $ans++;
    }
  }
}
echo "$ans\n";
