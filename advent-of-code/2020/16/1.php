<?

$mode = 1;

$fields = [];
$your = [];
$ans = 0;

foreach (file('input.txt') as $line) {
  $line = trim($line);
  if (!$line) continue;

  switch ($mode) {
    case 1:
      if ($line == 'your ticket:') {
        $mode = 2;
        break;
      }
      list($field, $rules) = explode(':', $line);
      $fields[$field] = [];
      $parts = explode(' or ', trim($rules));
      foreach ($parts as $part) {
        $fields[$field][] = explode('-', $part);
      }
      break;
    case 2:
      if ($line == 'nearby tickets:') {
        $mode = 3;
        break;
      }
      $your = explode(',', $line);
      break;
    case 3:
      $numbers = explode(',', $line);
      foreach ($numbers as $num) {
        $ok = false;
        foreach ($fields as $f => $field_rules) {
          foreach ($field_rules as $field_rule) {
            if ($num >= $field_rule[0] && $num <= $field_rule[1]) {
              $ok = true;
              break(2);
            }
          }
        }
        if (!$ok) {
          $ans += $num;
        }
      }
      break;
  }
}

// 2418068 too high
echo "$ans\n";
