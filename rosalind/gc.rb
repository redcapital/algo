id = gets.strip
highest_id = ''
highest = 0
while id
  current = n = 0
  while s = gets
    s.strip!
    if s[0] == '>'
      break
    else
      current += s.chars.count { |c| c == 'C' || c == 'G' }
      n += s.length
    end
  end
  current = current.to_f / n
  if current > highest
    highest, highest_id = current, id
  end
  id = s
end

puts highest_id[1..-1]
puts '%.2f%%' % (highest * 100)
