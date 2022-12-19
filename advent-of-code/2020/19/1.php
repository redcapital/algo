<?

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
      echo $compiled;
    }
    if (preg_match("/^{$compiled}$/", $line)) {
      $ans++;
    }
  }
}

echo "\nAns: $ans\n";
