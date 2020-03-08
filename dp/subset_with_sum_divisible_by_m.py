t = int(input())
for _ in range(t):
	n,m = list(map(int,input().split()))
	a = list(map(int,input().split()))

	dp = [[None for i in range(m+1)] for j in range n]

	def compute(a,n,m)