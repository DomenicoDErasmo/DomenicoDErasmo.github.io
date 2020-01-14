disp("First problem (Problem 2.8.1):")

%{
Write a MATLAB program which uses the upwind finite difference scheme
(2.35) to compute numerical solutions to the IBVP (assume c > 0)

du/dt + c(du/dx) = 0, 0 < x < 10, t > 0
u(x,0) = f(x), u(0,t) = g(t)

Let f(x) = (x-2)e^(-2(x-2)^2)
Let g(t) = arctan(t)
%}

c = .75;                                % coefficient in the transport equation
delx = .1;                              % change in x used in the scheme
delt = .1;                              % change in t used in the scheme
x = 0: delx: 10;                        % x is a vector of values from 0 to 10, incrementing in steps of 0.1
t = 0: delt: 10;                        % t is a vector of values from 0 to 10, incrementing in steps of 0.1
J = 10/delx;                            % set the number of spatial steps (100 in this case)
r = c*delt/delx;                        % simplifies the formula
nsteps = 100;                           % set the number of time steps (100 in this case)
u = f(x);                               % initializes the vector u
U = zeros(101,101);                     % initializes the values of the U(x,t) matrix to zero for easy editing

for n = 1:nsteps                        % calculates all u values from 0 to 10 on 40 t values
    v = u;                              % makes a copy of u for future use
    for j = 2:J+1                       % calculates 100 x values for u(x,t) for a given t value
        u(j) = (1-r)*v(j) + r*v(j-1);   % formula for the upwind finite difference scheme
        U(n,j) = u(j);                  % assigns a value for U so that the 3D graph of U(x,t) can be seen
    end
    plot(x,u)                           % plots a 2d graph along the x-u plane with a given slice of t
    axis([0 10 -0.5 0.5])               % makes a consistent window size
    pause(0.1)                          % makes a delay to allow one to see the progression of u as time increases
end

[X,T] = meshgrid(x,t);                  % creates the grid of x and t values used in the 3D plot of U(x,t)
mesh(X,T,U)                             % creates the graph of U(x,t)
pause(10)                               % keeps the graph on screen for ten seconds

disp("Second problem (Problem 2.8.2):")

%{
Again using the program in Section B.7 as model, write a MATLAB program as
above, but for the equation

du/dt + d[c(x)u]/dx = 0

Use a backward difference to approximate d[c(x)u]/dx. You will need a
function mfile for c(x).
%}

delx = .1;                              % initializes the change in x. smaller value -> more accurate u
delt = .1;                              % initializes the chagne in t. smaller value -> more accurate u 
x = 0: delx: 10;                        % x is a vector of values from 0 to 10, incrementing in steps of 0.1
t = 0: delt: 10;                        % t is a vector of values from 0 to 10, incrementing in steps of 0.1
J = 10/delx;                            % set the number of spatial steps
nsteps = 40;                            % set the number of time steps
u = f(x);                               % initialize the vector u
U = zeros(101,101);                     % initializes the values of the U(x,t) matrix to zero for easy editing

for n = 1:nsteps                        % calculates all u values from 0 to 10 on 40 t values
    v = u;                              % makes a copy of u for future use
    for j = 2:J+1                       % calculates 100 x values for u(x,t) for a given t value
        k = c*(j);                      % calculates the c(x) coefficient for the PDE at x = j
        r = k*delt/delx;                % simplifies the formula
        u(j) = (1-r)*v(j) + r*v(j-1);   % formula for the upwind finite difference scheme
        U(n,j) = u(j);                  % assigns a value for U so that the 3D graph of U(x,t) can be seen
    end
    plot(x,u)                           % plots a 2d graph along the x-u plane with a given slice of t
    pause(0.1)                          % makes a delay to allow one to see the progression of u as time increases
end

[X,T] = meshgrid(x,t);                  % creates the grid of x and t values used in the 3D plot of U(x,t)
mesh(X,T,U)                             % creates the graph of U(x,t)
pause(10)                               % keeps the graph on screen for ten seconds

disp("Third problem (Problem 2.8.4):")

%{
Consider the IVP

du/dt + (t-x^2/10)(du/dx) = 0, u (x,0) = f(x),

where f(x) = e^[-(x-3)^2]. The ODE for the characteristic curves is

dx/dt = t - x^2/10, x(0) = xo.      (2.52)

Write a MATLAB program which uses the ODE solver ode23 or ode45 to
numerically integrate (2.52) for a number of values of xo. Use the vector
of initial values xo = 0: .1:8, and integrate the ODE on the intervals [0,
tfinal] for 0 <= tfinal <= 2. Plot the curves with the x coordinate first
and then restric tthe rectangle of viewing by using the command axis([0 5 0
tfinal]). Let xfinal be the vector of terminal t values of the
characteristics. It should have the same size as xo. Use the fact that the
solution is constant on characteristics to plot a snapshot of the solution at time
tfinal.
%}

xo = 0: 0.1:8;                          % creates a vector of initial values from 0 to 8, in 0.1 increments
delt = 0.05;                            % initializes the change in time
tsteps = 2 / delt;                      % sets up the number of time steps
initial_conditions = P3Initial(xo);  

for n = tsteps:tsteps                   % calculates the x values for characteristics at a specific time set
    [x, t] = ode45('P3ODE', [0, n * delt], xo);
    plot (x, t)                         % plots a 2d graph of the characteristics along the x-t plane
    axis([0 2 0 20])                    % changed from the instructions to have a constant window size
    pause(10)                            % makes a delay to allow one to see the progression of u as time increases
end

plot(xo, initial_conditions)            % the values for u(x,0) are the same for u(x, tfinal)