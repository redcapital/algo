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
  $acc = evaluate_node(array_shift($nodes));
  while (!empty($nodes)) {
    list(, $op) = array_shift($nodes);
    $arg = evaluate_node(array_shift($nodes));
    switch ($op) {
      case '+':
        $acc += $arg;
        break;
      case '*':
        $acc *= $arg;
        break;
    }
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
