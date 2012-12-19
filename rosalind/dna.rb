File.open('rosalind1.txt', 'rb') do |f|
  s = f.read
  count = { 'A' => 0, 'C' => 0, 'G' => 0, 'U' => 0 }
  s.strip.chars { |c| count[c] += 1 }
  puts '%d %d %d %d' % [count['A'], count['C'], count['G'], count['U']]
end
