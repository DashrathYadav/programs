
mod=1000000007
def sum_of_squares(n):
 # ans= ((((((n)*(n+1))%mod)*(2*n+1))%mod)%mod)/6
  ans= ((n)*(n+1)*(2*n+1))//6
  return ans
 
def sum_of_linear(n):
    ans= (n*(n+1))//2
    return ans

t=int(input())
for i in range(0,t):
  n=int(input())
  ans=(2022*(sum_of_squares(n)+sum_of_squares(n-1) + sum_of_linear(n-1)))%mod
  print(ans)
