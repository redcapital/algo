<?

$ops = [];
foreach (file('input.txt') as $idx => $line) {
  sscanf($line, '%s %c%d', $opcode, $sign, $number);
  $ops[] = [$idx, $opcode, $sign, $number];
}

$seen = [];
$idx = 0;
$accumulator = 0;
while (true) {
  list($idx, $opcode, $sign, $number) = $ops[$idx];
  if (isset($seen[$idx])) {
    break;
  }
  $seen[$idx] = true;
  $number = $sign === '+' ? $number : -$number;
  switch ($opcode) {
    case 'acc':
      $accumulator += $number;
      $idx++;
      break;
    case 'jmp':
      $idx += $number;
      break;
    case 'nop':
      $idx++;
      break;
  }
}

// 22 is wrong
echo sprintf("Accumulator: %d\n", $accumulator);
