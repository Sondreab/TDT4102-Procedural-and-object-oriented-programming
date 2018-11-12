#bool isFibonacciNumber(int n){
#   int a = 0;
#   int b = 1;
#   while (b < n){
#       int temp = b;
#       b = a + b;
#       a = temp;
#   }
#   if (b == n){
#       return true;
#   }
#   else{
#       return false;
#   }
#}

def is_fibonacci_number(n):
    a = 0
    b = 1
    while b<n:
        temp = b
        b = a + b
        a = temp
    if b==n:
        return True
    else:
        return False
    
is_fibonacci_number(n)
