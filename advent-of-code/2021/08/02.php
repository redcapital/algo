<?

function strsort($s) {
  $p = str_split($s);
  sort($p);
  return implode($p);
}

function contain($s, $cand) {
  for ($i = 0; $i < strlen($cand); $i++) {
    if (strpos($s, $cand[$i]) === false) {
      return false;
    }
  }
  return true;
}

$ans = 0;
foreach (file('input.txt') as $line) {
  $s = trim($line);
  list($words, $d) = explode(' | ', $s);
  $out = array_map('strsort', explode(' ', $d));
  $words = array_map('strsort', explode(' ', $words));
  $map = [];
  $bylen = [];
  foreach ($words as $word) {
    $dist = strlen($word);
    if (isset($bylen[$dist])) $bylen[$dist][] = $word; else $bylen[$dist] = [$word];
  }

  $map[1] = $bylen[2][0];
  $map[4] = $bylen[4][0];
  $map[7] = $bylen[3][0];
  $map[8] = $bylen[7][0];

  // find 6
  foreach ($bylen[6] as $w) {
    if (!contain($w, $map[1])) {
      $map[6] = $w;
      break;
    }
  }

  // find 0 and 9
  foreach ($bylen[6] as $w) {
    if ($w == $map[6]) continue;
    if (contain($w, $map[4])) {
      $map[9] = $w;
    } else {
      $map[0] = $w;
    }
  }

  // find 3
  foreach ($bylen[5] as $w) {
    if (contain($w, $map[1])) {
      $map[3] = $w;
      break;
    }
  }

  // find 2 and 5
  foreach ($bylen[5] as $w) {
    if ($w == $map[3]) continue;
    if (contain($map[6], $w)) {
      $map[5] = $w;
    } else {
      $map[2] = $w;
    }
  }

  if (count($map) != 10) {
    die("fail\n");
  }

  $reverse = [];
  foreach ($map as $k => $v) $reverse[$v] = $k;

  $num = '';
  foreach ($out as $outword) {
    $num .= $reverse[$outword];
  }
  $ans += (int)$num;
}

echo "$ans\n";
