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
  $year = (int)$p['byr'];
  if ($year < 1920 || $year > 2002) {
    return false;
  }
  $year = (int)$p['iyr'];
  if ($year < 2010 || $year > 2020) {
    return false;
  }
  $year = (int)$p['eyr'];
  if ($year < 2020 || $year > 2030) {
    return false;
  }

  if (!preg_match('/^(\d+)(cm|in)$/', $p['hgt'], $m)) {
    return false;
  }
  $height = (int)$m[1];
  if ($m[2] == 'cm' && ($height < 150 || $height > 193)) {
    return false;
  }
  if ($m[2] == 'in' && ($height < 59 || $height > 76)) {
    return false;
  }

  if (!preg_match('/^#[0-9a-f]{6}$/', $p['hcl'])) {
    return false;
  }

  if (!in_array($p['ecl'], ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'])) {
    return false;
  }

  if (!preg_match('/^\d{9}$/', $p['pid'])) {
    return false;
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
