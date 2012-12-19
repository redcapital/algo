a, s = STDIN.gets.strip, STDIN.gets.strip
current = 0
while (current = a.index(s, current))
  current += 1
  print current, ' '
end
puts
