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