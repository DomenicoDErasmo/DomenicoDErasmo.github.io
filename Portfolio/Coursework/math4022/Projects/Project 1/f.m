function [y] = f(x)
% Test function for Project 1
%   The function is y = (x-2)e^-2(x-2)^2
u=exp(-2*(x - 2).^2);v = (x-2);
y = u .* v;
end

