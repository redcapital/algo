nodes = []

name = dna = ''
while s = gets
  s.strip!
  if s[0] == '>'
    unless dna.empty?
      nodes << { name: name, prefix: dna[0..2], suffix: dna[-3..-1] }
    end
    name = s[1..-1]
    dna = ''
  else
    dna << s
  end
end

nodes << { name: name, prefix: dna[0..2], suffix: dna[-3..-1] }

nodes.permutation(2).each do |p|
  puts p[0][:name] + ' ' + p[1][:name] if p[0][:suffix] == p[1][:prefix]
end
