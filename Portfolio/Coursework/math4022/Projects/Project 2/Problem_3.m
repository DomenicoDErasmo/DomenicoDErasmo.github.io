%{

Section 4.2 #4

Consider the solution of the IBVP (4.23)-(4.25) with initial data f(x) =
5sin(2pix/L) - 2sin(3pix/L) + 3sin(5pix/L).

(a) Find the solution. It should consist of three terms.

(b) Set L = pi and k = 1. Make an mfile u.m for the solution u(x,t),

    function w = u(x,t)
    w = ...

Plot snapshots of the solution for t = 0, 0.5, 1, 2, 5 with the
instructions

    x = 0:pi/100:pi;
    u0 = u(x,0); u1 = u(x,0.5); u2 = u(x,1);
    u3 = u(x,2); u4 = u(x,5);
    plot(x,u0,x,u1,x,u2,x,u3,x,u4)

Which term in the sum is a good approxiumation to the solution when t = 5?
Why?
%}

% See homework for work that leads to this solution
L = pi;

% Initializes x and all desired u(x,t)
x = 0:pi/100:pi;
u0 = u(x,0,L);
u1 = u(x,0.5,L);
u2 = u(x,1,L);
u3 = u(x,2,L);
u4 = u(x,5,L);

plot(x,u0,x,u1,x,u2,x,u3,x,u4)

legend('u0','u1','u2','u3','u4')

disp ("The third term is a good approximation to the solution when t=5, because it has an exp(-125) term, making the solution close to 0.")