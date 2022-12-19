<?

$input = trim(file_get_contents('input.txt'));

$seen = [];

foreach (explode(',', $input) as $idx => $num) {
  $seen[$num] = [$idx];
  $recent = $num;
}

for ($i = count($seen); $i < 2020; $i++) {
  if (count($seen[$recent]) < 2) {
    $recent = 0;
  } else {
    $recent = $seen[$recent][1] - $seen[$recent][0];
  }
  if (!isset($seen[$recent])) {
    $seen[$recent] = [$i];
  } else {
    $seen[$recent][] = $i;
    if (count($seen[$recent]) > 2) {
      array_shift($seen[$recent]);
    }
  }
}

// 436 is too high
// 0 incorrect
echo "$recent\n";
