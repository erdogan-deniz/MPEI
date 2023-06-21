function [x0, counter] = dixot(fun, a, b, delta, d, counter)

while d >= delta 
    x0 = (b + a) / 2;
    counter = counter + 1;
    l = b - a;
    x1 = a + l/4;
    x2 = b - l/4;
    y = feval(fun, x0);
    w = feval(fun, x1);
    z = feval(fun, x2);
    if w < y 
        b = x0 , x0 = x1
    else
        if z < y 
            a = x0, x0 = x2
        else 
            a = x1, b = x2;
        end;
    end;
    l = abs(b - a);
    d = l / 2;
    x0 = (b + a) / 2;
end;