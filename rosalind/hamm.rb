s1, s2 = STDIN.gets.strip, STDIN.gets.strip
puts (0...s1.length).count { |index| s1[index] != s2[index] }
