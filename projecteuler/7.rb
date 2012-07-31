N = 10001
primes = []

def prime_cap(x)
	flx = x.to_f
	flcap = 1.0
	f = 2
	while flcap <= flx
		flcap = f.to_f / (Math.log(f) - 1.08366)
		f += 1
	end
	f
end

n = prime_cap(N) + 2
sieve = Array.new(n + 1, true)
i = 2
while i <= n
	if (sieve[i])
		primes << i
		j = i * i
		while j <= n
			sieve[j] = false
			j += i
		end
	end
	i += 1
end

if primes.length >= N
	puts primes[N - 1]
else
	puts "Not found"
end
