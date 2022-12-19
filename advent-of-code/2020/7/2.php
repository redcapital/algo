<?

$children = [];

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

function getCount($id) {
  global $children;
  $res = 0;
  $bags = $children[$id] ?? [];
  foreach ($bags as $bag) {
    $res += $bag['count'] + $bag['count'] * getCount($bag['id']);
  }
  return $res;
}

foreach (file('input.txt') as $line) {
  list($p1, $p2) = explode('bags contain', $line);
  $p2 = trim($p2);
  if ($p2 === 'no other bags.') {
    continue;
  }
  $id = getBagId(trim($p1));
  if (!isset($children[$id])) {
    $children[$id] = [];
  }
  foreach (explode(',', $p2) as $def) {
    if (preg_match('/(\d+) (.+) bag/', $def, $matches)) {
      $children[$id][] = [
        'id' => getBagId($matches[2]),
        'count' => (int)$matches[1],
      ];
    }
  }
}

// 189 too low
echo sprintf("Bags: %d\n", getCount(getBagId('shiny gold')));
