function [x0, counter] = gold(fun, a, b, delta, d, counter)

x0 = 0;
L = (sqrt(5) - 1) / 2;

while d >= delta
    counter = counter + 1;
    x1 = a + (1 - L) * (b - a);
    x2 = a + L * (b - a);
    y = feval(fun, x1);
    w = feval(fun, x2);
    if y < w
        b = x2, x2 = x1, w = y, x1 = a + b - x2, y = feval(fun, x1);
    else
        a = x1, x1 = x2, y = w, x2 = a + b - x1, w = feval(fun, x2);
    end

    d = abs((b - a)) / 2;

    if d < delta
        x0 = (a + b)  / 2, break;
    end
end
