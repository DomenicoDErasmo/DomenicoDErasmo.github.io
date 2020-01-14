%{
Section 3.5 #2

Make an mfile for the function phi, including the dependence on the
parameters myeps, ul, and ur. Try

function u = phi(s, myeps, uleft, uright)
    denom = 1+exp(-.5*s*(uleft-uright)/myeps);
    u = uleft+ (uright-uleft)./denom;

Note that we cannot use eps as a variable, because this is already a system
constant. Plot phi for ul = 2, ur = 1, and several values of myeps, say
myeps = 0.02, 0.05, 0.1, 0.2. Plot the graphs on [-2, 2]. In each case
estimate the width of the transition region where phi makes 90% of its drop
from 2 to 1, that is, from 1.95 to 1.05.

Note: I made the graphs larger for clarity.
%}

% Function-specific variables
ul = 2;
ur = 1;
c = (ul+ur)/2;
myeps = 0.2;

% Setting up x variable
num_x = 200;
del_x = 5/num_x;
x = linspace(-2,10,num_x);

% Setting up t variable
num_t = 100;
max_t = 5;
del_t = max_t/num_t;

disp("Epsilon = 0.2")
disp ("Width of transition region for 90% of drop: ~2.10")

% Epsilon = 0.2
for t_step = 1:num_t

    u = phi(x-(c*(del_t*t_step)),myeps,ul,ur);
    plot(x, u)
    axis([-2 10 0 3])
    pause(0.05)
    
end

myeps = 0.1;

disp("Epsilon = 0.1")
disp ("Width of transition region for 90% of drop: ~1.20")

% With Epsilon = 0.1
for t_step = 1:num_t

    u = phi(x-(c*(del_t*t_step)),myeps,ul,ur);
    plot(x, u)
    axis([-2 10 0 3])
    pause(0.05)
    
end

myeps = 0.05;

disp("Epsilon = 0.05")
disp ("Width of transition region for 90% of drop: ~0.54")

% With Epsilon = 0.05
for t_step = 1:num_t

    u = phi(x-(c*(del_t*t_step)),myeps,ul,ur);
    plot(x, u)
    axis([-2 10 0 3])
    pause(0.05)
    
end

myeps = 0.02;

disp("Epsilon = 0.02")
disp ("Width of transition region for 90% of drop: ~0.24")

% With Epsilon = 0.02
for t_step = 1:num_t

    u = phi(x-(c*(del_t*t_step)),myeps,ul,ur);
    plot(x, u)
    axis([-2 10 0 3])
    pause(0.05)
    
end