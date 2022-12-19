<?

$ops = [];
foreach (file('input.txt') as $idx => $line) {
  sscanf($line, '%s %c%d', $opcode, $sign, $number);
  $number = $sign === '+' ? $number : -$number;
  $ops[] = [$idx, $opcode, $number];
}

function run(array $ops) {
  $size = count($ops);
  $seen = [];
  $idx = 0;
  $accumulator = 0;
  $result = [];
  $success = false;
  while (true) {
    list($idx, $opcode, $number) = $ops[$idx];
    if (isset($seen[$idx])) {
      break;
    }
    $seen[$idx] = true;
    $result[] = $ops[$idx];
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
    if ($idx === $size) {
      $success = true;
      break;
    }
  }
  return [$accumulator, $success, $result];
}

list(,, $result) = run($ops);

for ($i = 0; $i < count($result); $i++) {
  list($idx, $opcode) = $result[$i];
  if ($opcode === 'jmp' || $opcode === 'nop') {
    $ops[$idx][1] = $opcode === 'jmp' ? 'nop' : 'jmp';
    list($accumulator, $success) = run($ops);
    if ($success) {
      echo "Changed {$idx} to {$ops[$idx][1]}\n";
      echo sprintf("Accumulator: %d\n", $accumulator);
      break;
    }
    $ops[$idx][1] = $opcode;
  }
}
