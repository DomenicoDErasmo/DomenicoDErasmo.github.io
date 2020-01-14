function [y] = P3Initial(x)
% Initial condition for the third problem, equal to u(x,0)
%   f(x) = e^(-3(x-3)^2)
y = exp(-(x-3).^2);
end

