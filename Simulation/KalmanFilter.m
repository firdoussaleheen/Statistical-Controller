function Kf = KalmanFilter(A,B,C,D,G,W,V)
% [nx ny] = size(G);
% [mx my] = size(C);
% W = (1e-3)*eye(ny);
% V = (1e-5)*eye(mx);
Vinv = inv(V);
% solve the Kalman filter algebraic Riccati equation
Pf = care(A',C',G*W*G',V);
%calculate Kalman filter gain matrix
Kf = Pf*C'*Vinv;

% sys = ss(Ap,Bp,Cp,Dp);
% %use matlab kalman function
% % kest estimator model, L kalman filter gain, P algebraic riccati solution
% %
% [kest,L,P]  = kalman(sys,W,V,'current')
% Kf = L;
% Pf = P;

end
%KALMAN  Kalman state estimator.
%
%   [KEST,L,P] = KALMAN(SYS,QN,RN,NN) designs a Kalman estimator KEST for
%   the continuous- or discrete-time plant SYS. For continuous-time plants
%      .
%      x = Ax + Bu + Gw            {State equation}
%      y = Cx + Du + Hw + v        {Measurements}
%
%   with known inputs u, process disturbances w, and measurement noise v,
%   KEST uses [u(t);y(t)] to generate optimal estimates y_e(t),x_e(t) of 
%   y(t),x(t) by:
%       .
%      x_e  = Ax_e + Bu + L (y - Cx_e - Du)
%
%      |y_e| = | C | x_e + | D | u
%      |x_e|   | I |       | 0 | 
%
%   KALMAN takes the state-space model SYS=SS(A,[B G],C,[D H]) and the 
%   covariance matrices:
%
%      QN = E{ww'},     RN = E{vv'},     NN = E{wv'}.
%
%   The row size of QN specifies the length of w and NN is set to 0 when 
%   omitted. KALMAN returns the estimator gain L and the steady-state error 
%   covariance P (solution of the associated Riccati equation).
%
%   [KEST,L,P] = KALMAN(SYS,QN,RN,NN,SENSORS,KNOWN) handles more general 
%   situations where
%      * Not all outputs of SYS are measured
%      * The disturbance inputs w are not the last inputs of SYS.
%   The index vectors SENSORS and KNOWN then specify which outputs y of SYS
%   are measured and which inputs u to SYS are known. All other inputs of
%   SYS are assumed stochastic.

%   [KEST,L,P,M,Z] = KALMAN(SYS,QN,RN,...,TYPE) specifies the estimator
%   type for discrete-time plants SYS. The string TYPE is either 'current'
%   (default) or 'delayed'. KALMAN returns the estimator and innovation 
%   gains L and M and the steady-state error covariances:
%
%       P = E{(x - x[n|n-1])(x - x[n|n-1])'}   (Riccati solution)
%       Z = E{(x - x[n|n])(x - x[n|n])'}
%

