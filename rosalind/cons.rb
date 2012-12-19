matrix = {}
n = nil
while s = gets
  s.strip!
  n ||= s.length
  s.chars.each_with_index do |c, index|
    matrix[c] ||= Array.new(n, 0)
    matrix[c][index] += 1
  end
end

n.times do |index|
  print matrix.max_by { |k, v| v[index] }.at(0).to_s
end
puts
%w[A C G T].each { |base| puts "#{base}: #{matrix[base].join(' ')}" }
