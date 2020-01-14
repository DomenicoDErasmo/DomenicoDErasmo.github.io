function u = phi(s, myeps, uleft, uright)
    denom = 1+exp(-.5*s*(uleft-uright)/myeps);
    u = uleft+ (uright-uleft)./denom;
end
