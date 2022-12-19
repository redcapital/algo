<?

$mode = 1;

$fields = [];
$your = [];
$tickets = [];

function is_valid($value, array $field_rules) {
  foreach ($field_rules as $field_rule) {
    if ($value >= $field_rule[0] && $value <= $field_rule[1]) {
      return true;
    }
  }
  return false;
}

function is_valid_ticket(array $ticket) {
  global $fields;
  foreach ($ticket as $num) {
    $ok = false;
    foreach ($fields as $field_rules) {
      if (is_valid($num, $field_rules)) {
        $ok = true;
        break;
      }
    }
    if (!$ok) {
      return [false, $num];
    }
  }
  return [true, null];
}

//foreach (file('in2') as $line) {
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
      $tickets[] = $your;
      break;
    case 3:
      $numbers = explode(',', $line);
      list($valid, $badnum) = is_valid_ticket($numbers);
      if ($valid) {
        $tickets[] = $numbers;
        break;
      } else {
        echo "Discarding $line because $badnum \n";
      }
      break;
  }
}

/*
foreach ($fields as $f => $field_rules) {
  $indexes[$f] = [];
  for ($i = 0; $i < count($fields); $i++) {
    $ok = true;
    foreach ($tickets as $t) {
      if (!is_valid($t[$i], $field_rules)) {
        $ok = false;
        break;
      }
    }
    if ($ok) {
      $indexes[$f][] = $i;
    }
  }
}
print_r($indexes);
After inspecting the output I found the index order by hand.
So this is not a general solution.
 */

$indexes = [
  'arrival station' => 16,
  'route' => 12,
  'arrival location' => 17,
  'wagon' => 13,
  'class' => 4,
  'price' => 18,
  'departure track' => 2,
  'departure date' => 15,
  'departure time' => 11,
  'departure platform' => 8,
  'departure station' => 1,
  'departure location' => 5,
  'type' => 3,
  'row' => 10,
  'seat' => 14,
  'train' => 19,
  'arrival platform' => 0,
  'zone' => 9,
  'arrival track' => 6,
  'duration' => 7,
];

/*
 * helper to validate order
foreach ($tickets as $t) {
  foreach ($fields as $f => $field_rules) {
    $idx = $indexes[$f];
    if (!is_valid($t[$idx], $field_rules)) {
      echo "Bad ticket found\n";
      print_r($t) . "\n";
      echo "Value {$t[$idx]} not good for field $f\n";
      echo "\n";
    }
  }
}
 */

$ans = 1;
foreach ($fields as $f => $field_rules) {
  if (strpos($f, 'departure') === 0) {
    $ans *= $your[$indexes[$f]];
  }
}

echo "$ans \n";
