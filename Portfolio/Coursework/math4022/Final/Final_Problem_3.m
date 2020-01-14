%{

Problem 3

Write a program in MATLAB to numerically solve the  initial and boundary
value problem

u_tt = c^2u_xx, u(0,t) = u(L,t) = 0, u(x,0) = f(x), u_t(x,0) = g(x)

for 0 < x < L, 0 < t. Keep your functions f(x) and g(x) in the main script
m-file.

a) Solve the problem using both the explicit scheme and the implicit
scheme.

b) Generate a movie that plots the two solutions together.

%}

% Using the explicit scheme in Section 5.7 of the textbook

% Parameter Initialization
% del_t must be less than (del_x/c) to ensure stability
del_x = 0.25;
del_t = 0.125/2;

max_x = 10;
max_t = 10;

num_x = max_x/del_x+1;
num_t = max_t/del_t+1;

% Initializes x and t variables
x_explicit = linspace(0, max_x, num_x);
t_explicit = linspace(0, max_t, num_t);

c =1;
L = max_x;

s = c^2*(del_t/del_x)^2;

% Initializing boundary values 
u_explicit = zeros(num_x, num_t);

u_explicit(1,:) = 0;

u_explicit(num_x,:) = 0;

u_explicit(:,1) = f(x_explicit,L);

% Initializing second row, needed for explicit scheme
u_explicit(2:end-1,2) = f(x_explicit(2:end-1),L)+g(x_explicit(2:end-1))*del_t+(s/2)*(f(x_explicit(3:end),L)-2*f(x_explicit(2:end-1),L)+f(x_explicit(1:end-2),L));

% Explicit scheme: u(j,n+1) = 2(1-s)*u(j,n)+s(u(j+1,n)+u(j-1,n))-u(j,n-1)
for n = 3:num_t
    
   u_explicit(2:end-1, n) = 2*(1-s)*u_explicit(2:end-1,n-1)+s*(u_explicit(3:end,n-1)+u_explicit(1:end-2,n-1))-u_explicit(2:end-1,n-2);
    
end

% Implicit scheme: replace u_xx with (u(j+1,n+1)-2u(j,n+1)+u(j-1,n+1)) / (del_x)^2

% del_x must be less than (c*del_t) to ensure stability
del_x = 0.25;
del_t = 0.125/2;

max_x = 10;
max_t = 10;

num_x = max_x/del_x+1;
num_t = max_t/del_t+1;

s = c^2*(del_t/del_x)^2;

% Initializes x and t variables
x_implicit = linspace(0, max_x, num_x);
t_implicit = linspace(0, max_t, num_t);

u_implicit = zeros(num_x, num_t);
u_implicit(1,:) = 0;
u_implicit(num_x,:) = 0;

% Initializing first two rows of matrix
u_implicit(:,1) = f(x_implicit,L);
u_implicit(2:end-1,2) = f(x_implicit(2:end-1),L)+g(x_implicit(2:end-1))*del_t+(s/2)*(f(x_implicit(3:end),L)-2*f(x_implicit(2:end-1),L)+f(x_implicit(1:end-2),L));

% Initializing Matrix S
S = sparse(num_x-2, num_x-2);
m = size(S,1);
S(1:m+1:end) = 1+2*s;
S(2:m+1:end) = -s;
S(m+1:m+1:end) = -s;
S = S;
S_inv = S\eye(size(S,1));

for n = 3:num_t
    
    solution_vector = zeros(size(S,1),size(S,1));
    previous_row = u_implicit(2:end-1,n-1);
    two_rows_ago = u_implicit(2:end-1,n-2);
    solution_vector(:,n) = 2*previous_row(:) - two_rows_ago(:);
    u_implicit(2:end-1,n) = S_inv*solution_vector(:,n);
    
end

% Graphing 
for n = 1:num_t

    plot(x_explicit, u_explicit(:,n), x_implicit, u_implicit(:,n))
    legend("Explicit", "Implicit")
    axis ([0 10 -8 8])
    pause(0.1)
    
end

% Functions for initial conditions
function y = f(x,L)

y = sin(pi.*x/L);

end

function y = g(x)

y = x.*cos(x);

end

