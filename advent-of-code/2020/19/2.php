<?

// This PHP solution that compiles rules into a giant regex didn't work :(
// I coded a C++ solution instead that implements a manual matching algorithm
// I decided to leave this PHP code here too.

function parse_rule($s) {
  list($id, $def) = explode(': ', $s);
  $rules = [];
  foreach (explode(' | ', $def) as $part) {
    if ($part[0] === '"') {
      $rules[] = ['literal', substr($part, 1, -1)];
    } else {
      $rules[] = ['nonterminal', explode(' ', $part)];
    }
  }
  return [$id, $rules];
}

function compile(array $grammar, $id = 0) {
  static $cache = [];
  if (isset($cache[$id])) {
    return $cache[$id];
  }
  $parts = [];
  foreach ($grammar[$id] as $rule) {
    if ($rule[0] === 'literal') {
      $parts[] = $rule[1];
    } else {
      $sub_compiled = '';
      foreach ($rule[1] as $sub_id) {
        $sub_compiled .= compile($grammar, $sub_id);
      }
      $parts[] = $sub_compiled;
    }
  }

  $result = count($parts) === 1 ? $parts[0] : '(?:' . implode('|', $parts) . ')';

  if ($id == 8) {
    $result = $result . '+';
  }
  if ($id == 11) {
    $rule_42 = compile($grammar, 42);
    $rule_31 = compile($grammar, 31);
    $result = '(?:' . $rule_42 . '(?:' . $rule_42 . $rule_31 . ')*' . $rule_31 . ')';
  }

  return $cache[$id] = $result;
}

$grammar = [];
$compiled = '';
$ans = 0;

foreach (file($argv[1]) as $line) {
  $line = trim($line);
  if (!$line) continue;
  if (strpos($line, ':') !== false) {
    list($id, $rules) = parse_rule($line);
    $grammar[$id] = $rules;
  } else {
    if (!$compiled) {
      $compiled = compile($grammar);
    }
    if (preg_match("/^{$compiled}$/", $line)) {
      $ans++;
    }
  }
}

// 217 is too low
echo "Ans: $ans\n";
