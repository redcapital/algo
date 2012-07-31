num = 600851475143
divisor = 2
while num > 1
  while num % divisor > 0 ; divisor += 1; end
  while num % divisor == 0
    num /= divisor
  end
end
puts divisor
