ans = 0
numbers = (100..999).to_a
numbers.each do |a|
	numbers.each do |b|
		p = a * b
		s = p.to_s
		ans = p if p > ans && s == s.reverse
	end
end
puts ans
