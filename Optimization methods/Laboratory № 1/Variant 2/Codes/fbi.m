function x0 = fbi(fun, a, b, n, fib)

for k = 1: n - 2 
x1 = a + (b - a) * fib(n-2) / fib(n)
x2 = a + (b - a) * fib(n-1) / fib(n)
y = feval(fun, x1);
z = feval(fun, x2);
if y <= z
    b = x2, x2 = x1, z = y, x1 = a + b - z, y = feval(fun, x1);
else
    a = x1, x1 = x2, y = z, x2 = a + b - x1, z = feval(fun, x2);
end
if y > z
    x0 = x1
else
    x0 = x2
end
end
