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

clear all

%{

Section 3.7 #1

Write a MATLAB program to implement the explicit finite difference scheme
(3.33). Set k = 1 and use the boundary conditions u = 0 at x = 0 and x =
10. Write an mfile f.m for the initial data. Try out your program with
initial data f(x) = sin(pix/10).

Fix del_x = 0.5 and then experiment with various values of del_t to see
when the schema becomes stable. Your observations should agree witht he
results of Section 3.6.

Compare your computed results wth the exact solution

u(x,t) = sin(pi*x/10)exp(-(pi/10)^2*t)

at various times, with del_t = 0.125. Find the maximum error at each time.
Use help max to see how to have MATLAB do this.

Now reduce the spatial step size to del_x = 0.25, and make del_t =
(del_x)^2/2. Again compare the computed solution adn the exact solution at
the same times you did before when del_x = 0.5. Is the error smaller? How
much?

%}

disp("Finite Differences Method with del_t = 0.2:")

% Initializing x variable
del_x = 0.5;
x_max = 10;
num_x = x_max / del_x + 1;
x = linspace(0, x_max, num_x);

% Initializing t variable
t_max = 10;
del_t = 0.2;
num_t = t_max / del_t + 1;
t = linspace(0, t_max, num_t);

% Other function-specific variables
k = 1;
s = k*del_t/(del_x)^2;

% Initializing u
u = zeros(num_x, num_t);
u(1,:) = 0;
u(num_x,:) = 0;
u(:,1) = f(x.');

% Initializing Solution
w = zeros(num_x, num_t); 
w = Problem_2_Exact_Solution(x.',t);

% del_x = 0.5, del_t = 0.2, leads to instability
for n = 2:num_t

    % Number scheme
    u(2:end-1, n) = (1-2*s)*u(2:end-1,n-1) + s*(u(3:end,n-1) + u(1:end-2,n-1));
    
    % Plotting
    plot(x,u(:,n),x,w(:,n))
    title("Finite Scheme with del_x = 0.5, del_t = 0.2")
    legend("Finite Differences Scheme","Exact Solution")
    axis([0 10 -1.5 2.5])
    pause(0.1)

end

pause()

% Initializing Error Matrix
error = zeros(num_x, num_t);
error = max(abs(minus(u,w)));

% Plots Error
plot (t, error)
title("Max Error at Every Time t")
pause()

% Next solution approximation: del_t = 0.125, which is stable
disp("Now using del_t = 0.125:")
del_x = 0.5;
del_t = 0.125;

% Update del_t-dependent variables
num_t = t_max / del_t + 1;
s = k*del_t/(del_x)^2;

% Initializing u
u = zeros(num_x, num_t);
u(1,:) = 0;
u(num_x,:) = 0;
u(:,1) = f(x.');

% Initializing Solution
t = linspace(0, t_max, num_t);
w = zeros(num_x, num_t); 
w = Problem_2_Exact_Solution(x.',t);

% del_x = 0.5, del_t = 0.125, leads to stability
for n = 2:num_t
    
    % Number scheme
    u(2:end-1, n) = (1-2*s)*u(2:end-1,n-1) + s*(u(3:end,n-1) + u(1:end-2,n-1));
    
    % Plotting
    plot(x,u(:,n),x,w(:,n))
    title("Finite Scheme with del_x = 0.5, del_t = 0.125")
    legend("Finite Differences Scheme","Exact Solution")
    axis([0 10 -1.5 2.5])
    pause(0.1)

end

pause()

% Initializing Error Matrix
error = zeros(num_x, num_t);
error = max(abs(minus(u,w)));

% Plotting Error
plot (t, error)
title("Max Error at Every Time t")
pause()

% Begins del_x = 0.25, del_t = 1/32, making a stable solution
% Sometimes the graph doesn't show right away, I'm not quite sure why
disp("Now using del_x = 0.25, del_t = 1/32")

% Initializing x variable
del_x = 0.25;
x_max = 10;
num_x = x_max / del_x + 1;
x = linspace(0, x_max, num_x);

% Initializing t variable
t_max = 10;
del_t = (del_x)^2/2;
num_t = t_max / del_t + 1;
t = linspace(0, t_max, num_t);

% Updating other variables
k = 1;
s = k*del_t/(del_x)^2;

% Initializing u
u = zeros(num_x, num_t);
u(1,:) = 0;
u(num_x,:) = 0;
u(:,1) = f(x.');

% Initializing Solution
w = zeros(num_x, num_t); 
w = Problem_2_Exact_Solution(x.',t);

% del_x = 0.25, del_t = 1/32, leads to stability
for n = 2:num_t

    % Number scheme
    u(2:end-1, n) = (1-2*s)*u(2:end-1,n-1) + s*(u(3:end,n-1) + u(1:end-2,n-1));
    
    % Plotting
    plot(x,u(:,n),x,w(:,n))
    title("Finite Scheme with del_x = 0.25, del_t = 0.03125")
    legend("Finite Differences Scheme","Exact Solution")
    axis([0 10 -1.5 2.5])
    
    % No delay to speed things up

end

pause()

% Initializing Error Matrix
error = zeros(num_x, num_t);
error = max(abs(minus(u,w)));

% Plot Errors
plot (t, error)
title("Max Error at Every Time t")
pause()

disp ("With halved del_x, the error is smaller by an order of magnitude.")

clear all

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
u0 = u_Problem_3(x,0,L);
u1 = u_Problem_3(x,0.5,L);
u2 = u_Problem_3(x,1,L);
u3 = u_Problem_3(x,2,L);
u4 = u_Problem_3(x,5,L);

plot(x,u0,x,u1,x,u2,x,u3,x,u4)

legend('u0','u1','u2','u3','u4')

disp ("The third term is a good approximation to the solution when t=5, because it has an exp(-125) term, making the solution close to 0.")

clear all

%{

Section 4.5 #1

Consider the boundary value problem for steady-state heat flow on the
interval [0,10] with a source q(x):

-ku"(x)=q(x), u(0) = u(10) = 0.

The goal is to write a MATLAB program to solve this problem numerically for
given data q. Make mesh poiints xj = j*del(x, j = 1, ... ,J where del_x =
10/J. Then write a finite difference scheme by replacing the second
derivative by a centered difference.

-k*((u(x(j) + del(x)) - 2*u(x(j)) + u*(x(j) - del_x)/(del_x)^2) ~= q(x(j)),

j = 1, ... ,J-1. Taking into account the boundary conditions, we arrive at
the (J-1) x (J-1) system

    kTu = q.

where u = [u_1, ... , u_(J-1)] is the vector of unknowns, q = [q(x(1), ...,
q(x(J-1))] and T = (del_x)^-2S where S is the sparse matrix

    S =  2 -1  0  0  0
        -1  2 -1  0  0
         0 -1  2 -1  0
         .  .  .  .  .
         .  .  .  .  .
         0  0  0 -1  2

You will need to write a function mfile q.m for q. Then use the sparse
matrix operations of MATLAB to enter the matrix S. For information enter
help sparse.

To see if your program works correctly, try q(x) = 1. The exact solution of
the BVP is u(x) = 0.5*x*(10-x)/k. The centered difference formula for u" is
exact on quadratic polynomials. Thus the vector of values u should agree
exactly with the values of u at the grid points. Try J = 5 to begin. When
you have gotten your program working correctly, try several different
choices of q with J = 100. Plot q and the solution together on the interval
[0, 10]. The vector of values u, which you get from solving (4.54), does
not include the zero values at the end points x = 0 and x = 10. You must
add these values to make a vector of (J + 1) components for plotting.

Next determine the reate of convergence of the computed solution values to
the values of an exact solution. Take q(x) = sin(pi*x/10). q is the first
eigenfunction phi_1(x) of this BVP. Hence the exact solution of -ku" = q =
phi_1 is given by

    u(x) = (1/k*lambda_1) * phi_1(x) = (1/k)*(10/pi)^2*sin(pi*x/10).

Now take the number of intervals to be J = 5, 10, 20, 40, 80. For each
value of J, find the maximum error between the calculated values and the
values of the exact solution at the grid points. What happens to this error
when J is doubled (that is, del_x is halved)?

The matrix operator T is an approximation to the differential operator Mu =
-u" with the boundary conditions u(0) = u(10) = 0. You can find the
eigenvalues of the matrix T with the single MATLAB command eig(T). Put them
in order of increasing size and compare with the eigenvalues of M. What do
you see happening as J gets larger?

%}

% Used for any num_x value
max_x = 10;
k = 1;
number_of_points = [5 10 20 40 80];
errors = zeros(size(number_of_points.'));
max_runs = size(number_of_points,2);
eigs_of_T = errors;

% Used a for loop instead of pasting code to make it cleaner
for loop_of_program = 1:max_runs

    % Initializing x variable
    num_x = number_of_points(loop_of_program);
    del_x = max_x/num_x;
    x = del_x:del_x:max_x-del_x;

    % Initializing S and T matrices
    S = sparse(num_x-1, num_x-1);
    m = size(S,1);
    S(1:m+1:end) = 2;
    S(2:m+1:end) = -1;
    S(m+1:m+1:end) = -1;
    T = S/(del_x)^2;
    T_inv = T\eye(size(T,1));

    % Showing eigenvalues
    current_eigs_of_T = eig(T)
    
    % Initializing the q solution
    q_exact = zeros(size(x.'));
    for x_pos = 1:num_x-1
        
        q_exact(x_pos) = q_4(x(x_pos));
        
    end

    % Initializing and solving u
    u = zeros(size(T,1));
    u = T_inv*(1/k)*q_exact;

    % Appending the boundary conditions for u and x to get a 
    % J+1 x J+1 matrix
    u_final = zeros(size(u,1)+2,1);
    u_final(2:end-1) = u;

    x_final = zeros(size(x,2)+2,1);
    x_final(2:end-1) = x;
    x_final(end) = 10;

    % Calculates error
    exact_values = u_exact(x_final,k);
    max_error = max(abs(u_final - exact_values));
    errors(loop_of_program) = max_error;
    
    % Plots numerical solution for u and actual solution for u
    plot (x_final,u_final,x_final,exact_values)
    legend("Experimental u", "Exact u")

    pause()
    
end

% Plots error over number of x and describes relation of eigenvalues and
% error to the number of x
disp("The max error halves and the eigenvalues of T span 4 times the range of numbers when del_x is halved.")
plot(number_of_points, errors)
legend("Max error")
title ("Max Error vs del_x")
pause()

clear all

%{

Section 4.5 #2

Consider the same boundary value problem as above, but with a piecewise
constant diffusion function k = k(x). For example, take k(x) = k_l for
0 <= x < 5 and k(x) = 1 for 5 <= x <= 10, and make k_l an input parameter.
The linear system to solve will use the jump conditions in Section 3.1.

%}

k_l = input("Enter a value for k_l: ");

% Used for any num_x value
max_x = 10;
number_of_points = [5 10 20 40 80];
max_runs = size(number_of_points,2);

% Runs the program with different numbers of points
% Constructs a number scheme for -ku" = q by solving kTu = q
for loop_of_program = 1:max_runs

    % Initializing x variable
    num_x = number_of_points(loop_of_program);
    del_x = max_x/num_x;
    x = del_x:del_x:max_x-del_x;
    
    k_vector = zeros(size(x));
    
    % Initialize all k values
    for k_x_pos = 1:num_x-1
       
        k_vector(k_x_pos)= k(x(k_x_pos),k_l);
        
    end
    
    % Setting T up, T = S/(del_x)^2
    S = sparse(num_x-1, num_x-1);
    m = size(S,1);
    S(1:m+1:end) = 2;
    S(2:m+1:end) = -1;
    S(m+1:m+1:end) = -1;

    T = S/(del_x)^2;
    T_inv = T\eye(size(T,1));
 
    q_exact = zeros(size(x.'));
    
    % Initializing q for all x
    for q_x_pos = 1:num_x-1
        
        q_exact(q_x_pos) = q_4(x(q_x_pos));
        
    end

    % Initializing u and a corresponding exact values array
    u = zeros(1,num_x-1);
    u_final = zeros(size(u,2)+2,1);
    temp_exact_values = zeros(size(u,1),1);
    
    % Initializing for all u values, couldn't do without a for loop sadly
    for u_x_pos = 1:num_x-1
        
        q_test = q_exact/k_vector(u_x_pos);
        T_column = T_inv(u_x_pos,:);
        u(u_x_pos) = T_column*q_test;
        temp_exact_values(u_x_pos) = u_exact(x(u_x_pos),k_vector(u_x_pos));
        
    end
    
    % Expanding previous arrays to accomodate for boundary conditions
    u_final(2:end-1) = u;

    x_final = zeros(size(x,2)+2,1);
    x_final(2:end-1) = x;
    x_final(end) = 10;
    
    k_final = ones(size(k_vector,2)+2,1);
    k_final(2:end-1) = k_vector;
    
    % My exact values seem to be off in the indivual file but worked during
    % my tests for the whole program. I'm not entirely sure why.
    exact_values = zeros(size(u,2)+2,1);
    exact_values(2:end-1) = temp_exact_values;
    
    % Plotting
    plot (x_final,u_final,x_final,exact_values)
    legend("Experimental u", "Exact u")

    pause()
    
end

clear all

%{

Generate a "movie" of the solution to the problem utt = uxx with u(x,0) = 0
and ut(x,0) = g(x) for -inf<x<inf and 0<t where 

g(x) = {1, |x| < 1
       {0, otherwise

%}

c = 1;

% Intializing x variable
end_x = 20;
del_x = 0.2;
num_x = end_x/del_x;
x = linspace(-end_x, end_x, num_x*2+1);

% Initializing t variable
end_t = 2 * end_x;
del_t = 0.2;
num_t = end_t/del_t;
t = linspace(del_t, end_t, num_t+1);

% Initializes the g function over a vector
g_curve = ones(size(x));
for x_pos = 1:size(x.')
    
    g_curve(x_pos) = g(x(x_pos));
    
end

% Sets up u to be filled later
u = zeros(size(x,2), size(t,2));
for t_step = 1:size(t.')/2
    
    % Sets up each time of u
    u(:,t_step) = zeros(size(x));
    
    % Fills each x in for every t 
    % I hate using nested for loops but I couldn't think of another way to
    % handle g(x)
    for x_step = 1:size(x.')
        
        % Sets up upper and lower bounds
        upper_bound = x(x_step)+c*t(t_step);
        lower_bound = x(x_step)-c*t(t_step);
        
        % Sets up integration domain
        num_integration_x = int32((upper_bound - lower_bound)*5 + 1);
        integration_domain = linspace(lower_bound, upper_bound, num_integration_x);
        number_of_points_to_integrate = size(integration_domain,2);
        
        % Specifies where to integrate within g
        g_curve = ones(size(integration_domain.'));
        
        %
        for integration_pos = 1:number_of_points_to_integrate
    
            g_curve(integration_pos) = g(integration_domain(integration_pos));
    
        end
        
        % Solution of u(x,t)
        % Because u(x,0) = 0, f(x) = 0, meaning we can ignore it
        u(x_step,t_step) = trapz(integration_domain, g_curve)/(2*c);
         
    end
    
    % Plots the current time slice of u(x,t)
    plot(x,u(:,t_step))
    axis ([-end_x end_x -1 2])
    pause(0.1)
    
end
