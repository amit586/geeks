t = int(input())

for _ in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	if sum(a)%2==1:
		print("NO")
		continue
	dp = [[None for i in range(sum(a)/2+1)] for j in range(n+1)]

	def subsetSum(a,n,s):
		if dp[n][s] is None:
			if(s==0):
				dp[n][s]=True
			elif(s!=0  and n==0):
				dp[n][s]=False
			elif s<a[n-1]:
				dp[n][s]=subsetSum(a,n-1,s)
			else:
				dp[n][s]=subsetSum(a,n-1,s) or subsetSum(a,n-1,s-a[n-1])

		return dp[n][s]

	if(subsetSum(a,n,sum(a)/2)):
		print('YES')
	else:
		print('NO')

