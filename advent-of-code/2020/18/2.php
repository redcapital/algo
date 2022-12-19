<?

function parse($s, $i = 0) {
  $nodes = [];
  while ($i < strlen($s)) {
    switch ($s[$i]) {
      case ' ':
        $i++;
        break;
      case '+':
      case '*':
        $nodes[] = ['op', $s[$i]];
        $i++;
        break;
      case '(':
        list($subnodes, $i_next) = parse($s, $i + 1);
        $nodes[] = ['sub', $subnodes];
        $i = $i_next;
        break;
      case ')':
        return [$nodes, $i + 1];
      default:
        $num = '';
        while ($i < strlen($s) && ctype_digit($s[$i])) {
          $num .= $s[$i];
          $i++;
        }
        $nodes[] = ['literal', (int)$num];
        break;
    }
  }
  return [$nodes, $i];
}

function evaluate_node(array $node) {
  list($type, $param) = $node;
  switch ($type) {
    case 'sub':
      return evaluate($param);
    case 'literal':
      return $param;
  }
}

function evaluate(array $nodes) {
  for ($i = 1; $i < count($nodes); $i += 2) {
    if ($nodes[$i][1] === '+') {
      $value = evaluate_node($nodes[$i - 1]) + evaluate_node($nodes[$i + 1]);
      $new = array_slice($nodes, 0, $i - 1);
      $new[] = ['literal', $value];
      $new = array_merge($new, array_slice($nodes, $i + 2));
      return evaluate($new);
    }
  }
  $acc = 1;
  for ($i = 0; $i < count($nodes); $i += 2) {
    $acc *= evaluate_node($nodes[$i]);
  }
  return $acc;
}

function calc($s) {
  list($nodes) = parse($s);
  return evaluate($nodes);
}

$ans = 0;
foreach (file($argv[1]) as $line) {
  $ans += calc(trim($line));
}

echo "$ans\n";
