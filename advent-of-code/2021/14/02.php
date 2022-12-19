<?

$temp = '';
$rules = [];
foreach (file('input.txt') as $line) {
  $line=trim($line);
  if (!$line) continue;
  if (!$temp) {
    $temp=$line;
    continue;
  }
  list($rule, $c) = explode(' -> ', $line);
  $rules[$rule] = $c;
}

$counts = [0 => [], 1 => []];
$pcnt = [];

for ($i = 0; $i < strlen($temp) - 1; $i++) {
  $s = $temp[$i] . $temp[$i + 1];

  if (isset($counts[0][$s])) {
    $counts[0][$s]++;
  } else {
    $counts[0][$s] = 1;
  }

  if (isset($pcnt[$temp[$i]])) {
    $pcnt[$temp[$i]]++;
  } else {
    $pcnt[$temp[$i]] = 1;
  }
}

$i = strlen($temp) - 1;
if (isset($pcnt[$temp[$i]])) {
  $pcnt[$temp[$i]]++;
} else {
  $pcnt[$temp[$i]] = 1;
}

//print_r($pcnt);die();

$cur = 0;

for ($i = 0; $i < 40; $i++) {
  $nc = ($cur + 1) % 2;
  $counts[$nc] = [];

  foreach ($counts[$cur] as $s => $cnt) {
    if (!isset($rules[$s])) {
      if (isset($counts[$nc][$s])) {
        $counts[$nc][$s] += $cnt;
      } else {
        $counts[$nc][$s] = $cnt;
      }
    } else {
      $char = $rules[$s];
      $s1 = $s[0] . $rules[$s];
      $s2 = $rules[$s] . $s[1];

      if (isset($counts[$nc][$s1])) {
        $counts[$nc][$s1] += $cnt;
      } else {
        $counts[$nc][$s1] = $cnt;
      }

      if (isset($counts[$nc][$s2])) {
        $counts[$nc][$s2] += $cnt;
      } else {
        $counts[$nc][$s2] = $cnt;
      }

      //echo "increase $char\n";
      if (isset($pcnt[$char])) {
        $pcnt[$char] += $cnt;
      } else {
        $pcnt[$char] = $cnt;
      }
    }
  }

  $cur = $nc;
}


$min = -1;
$max = -1;
foreach ($pcnt as $cnt) {
  if ($min < 0) {
    $min = $max = $cnt;
  } else {
    $min = min($min, $cnt);
    $max = max($max, $cnt);
  }
}

echo ($max - $min);
echo "\n";
