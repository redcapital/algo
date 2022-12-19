<?

$parents = [];

function getBagId($name, $d = false) {
  static $id = 1;
  static $ids = [];
  if ($d) {
    print_r($ids);
    return 1;
  }
  if (!isset($ids[$name])) {
    $ids[$name] = $id++;
  }
  return $ids[$name];
}

foreach (file('input.txt') as $line) {
  list($p1, $p2) = explode('bags contain', $line);
  $p2 = trim($p2);
  if ($p2 === 'no other bags.') {
    continue;
  }
  $id = getBagId(trim($p1));
  foreach (explode(',', $p2) as $def) {
    if (preg_match('/(\d+) (.+) bag/', $def, $matches)) {
      $bagId = getBagId($matches[2]);
      if (!isset($parents[$bagId])) {
        $parents[$bagId] = [];
      }
      $parents[$bagId][] = $id;
    }
  }
}

$seen = [];
$stack = [getBagId('shiny gold')];

while (!empty($stack)) {
  $id = array_pop($stack);
  if (!isset($seen[$id])) {
    $seen[$id] = true;
    if (isset($parents[$id])) {
      $stack = array_merge($stack, $parents[$id]);
    }
  }
}

echo sprintf("Bags: %d\n", count($seen) - 1);
