<?

list($estimate, $list) = file('input.txt');
$estimate = (int)$estimate;

$delay = 1000000;
$ans = 0;
foreach (explode(',', $list) as $bus) {
  if ($bus == 'x') continue;
  $rem = $estimate % (int)$bus;
  if ($rem === 0) {
    echo "0\n";
    exit(0);
  }
  if ($bus - $rem < $delay) {
    $delay = $bus - $rem;
    $ans = $bus * $delay;
  }
}

echo "$ans\n";
