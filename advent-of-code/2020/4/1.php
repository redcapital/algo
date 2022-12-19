<?

$lines = file('input.txt');

$fields = [
  'byr', 
  'iyr', 
  'eyr', 
  'hgt', 
  'hcl', 
  'ecl', 
  'pid', 
  'cid', 
];

function validate($p) {
  global $fields;
  foreach ($fields as $f) {
    if ($f != 'cid' && !isset($p[$f])) {
      return false;
    }
  }
  return true;
}

$current = [];
$ans = 0;
foreach ($lines as $line) {
  $line = trim($line);
  if ($line) {
    $parts = explode(' ', $line);
    foreach ($parts as $p) {
      if (!$p) continue;
      $s = explode(':', $p);
      $current[$s[0]] = $s[1];
    }
  } else {
    if (validate($current)) {
      $ans++;
    }
    $current = [];
  }
}

validate($current);

echo "$ans\n";
