function [Kmcv,emcv] = MCVController(A,B,C,D,G,W,gama)
global n %% System matrix is n x n
global k %% k = number of cumulants
global L 
%global G
format shortg
syms s m x t


n = length(A);
m = size(B,2);
p = size(G,2);
k = 2;

nx = length(A);
[mx my] = size(B);
Q = eye(nx);
R = 1*eye(my);
Rinv = inv(R);

gamma = zeros(1,k);
gamma(1)=1;
gamma(2)=gama;

%x0 = zeros(n,1);            %% n x 1 initial conditions
L = k;                      %% counter for continued fractions

t0 = 0;
tf = 5;
tspan = [t0 tf];        % integration time span
X_final = zeros(k*n,n); % terminating conditions
%options = odeset('RelTol',1e-6,'Stats','on');
tic
%[T X] = ode45(@mRiccati, tspan, X_final, [], A, B, Q, R, G, W, n, gamma, k);
[T X] = ode15s(@mRiccati, tspan, X_final, [], A, B, Q, R, G, W, n, gamma, k);
toc
%[T X] = ode45(@mRiccati, tspan, X_final, [], A, B, Q, R, G, W, n, gamma, k);
                        % X = solution of differentials over tspan
                        % X is a integrated backwards in time
                        % thus first row of X is terminal values
                        % last row of X is initial values
X = flipud(X);          % flips X


% Reshape X matrix and find M and V
% M = Hmat{1} and V = Hmat{2}
% Hmat = matrix_construct(k, n, X);
Hcumulants = calc_cumulant(X, k,n);
M = Hcumulants{1};
V = Hcumulants{2};

gammamcv = gamma(2)/gamma(1);

% Calculate K for MCV case
P = (M+gammamcv*V);
Kmcv = Rinv*B'*P;
emcv = eig(A-B*Kmcv);
end