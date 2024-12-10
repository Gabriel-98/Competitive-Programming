from random import randint
 
def getBinario(n):
	binario = []
	while n > 0:
		binario.append(int(n%2))
		n = int(n/2)
	return binario
 
def exponenciacion(base, exponente, modulo):
	binario = getBinario(exponente)
	potencias = [base] + [0 for i in range(1, len(binario))]
	for i in range(1, len(binario)):
		potencias[i] = (potencias[i-1] * potencias[i-1]) % modulo
	ans = 1
	for i in range(len(binario)):
		if binario[i] == 1:
			ans = (ans * potencias[i]) % modulo
	return ans
 
def miller_rabin(n):
	iteraciones = 100
	if n == 2 or n == 3:
		return 1
	if n > 1 and n % 2 == 1:
		# n - 1 = m*2^k
		m = n - 1
		k = 0
		while m % 2 == 0:
			k += 1
			m = int(m / 2) 
		for iteracion in range(iteraciones):
			a = randint(2, n-2)
			# b = (a^m) mod n
			b = exponenciacion(a,m,n)
			if not(b == 1 or b == n-1):
				for i in range(1, k):
					b = (b*b) % n
					if b == n-1:
						break
				if b != n-1:
					return 0
		return 1
	return 0
 
 
if __name__ == '__main__':
	t = int(input())
	for test in range(0,t):
		n = int(input())
		if miller_rabin(n) == 1:
			print("YES")
		else:
			print("NO")
