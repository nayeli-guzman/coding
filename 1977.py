
num="234567"
n=len(num)

dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(n):
    for l in range(1,i+2):
        j = i-l+1 # 

        maxL2 = 0 # representa la longitud de L2 | L2 <= L
        if(j<l):
            maxL2=j
        elif (num[j-l:j] <= num[j:i+1]):
            maxL2 = l
        else:
            maxL2 = l-1

        for l2 in range(1,maxL2+1):
            dp[i][l] += dp[j-1][l2]
    print(sum(dp[n-1]))

print(dp)