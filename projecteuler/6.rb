N = 100
sum = (N * (1 + N)) / 2
puts (1..N).reduce(0) { |memo, num| memo + num * (sum - num) }
