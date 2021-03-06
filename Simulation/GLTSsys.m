%% Linearized Gimbaled Laser Target System
clear all;
close all;
clc;
format shortg
%% Simulation parameters for servo motor drive
Ra= 2*1.3; % motor resistance 
La = 2*1.4e-3; %motor inductance
Jm = 1.13e-5; % motor moment of inertia 
b = 0.0000365; % motor damping co-efficient
kb = 0.0678; % flux linkage

Jex = 0.00565; % pitch gimbal moment of inertia component
Jey = 0.036725; % pitch gimbal moment of inertia component
Jez = 0.0226; % pitch gimbal moment of inertia component
Kef = 0.01*0.06328; % friction coefficient
Kew = 0.01*0.0113; % cable restraint coefficient
N = 90; %gear ratio
%%
Jax = 0.0113; % yaw gimbal moment of inertia component
Jay = 0.0452; % yaw gimbal moment of inertia component
Jaz = 0.0678; % yaw gimbal moment of inertia component
Ja = Jaz+Jez;
Kaf = 0.01*0.06328; % friction coefficient
Kaw = 0.01*0.0113; % cable restraint coeffient

%% pitch gimbal servo param
Jt1 = Jey + N*N*Jm;
bt1 = Kef + N*N*b;
taum1 = Jt1/bt1;
K1 = bt1/(kb*kb*N + Ra*bt1);

%% yaw gimbal servo param
Jt2 = Ja + N*N*Jm;
bt2 = Kaf + N*N*b;
taum2 = Jt2/bt2;

%% Current Loop transfer function
%G_current = ia/iastar
% motor constant
tau1 = (0.5*((Jt1*Ra+bt1*La) + sqrt((Jt1*Ra+bt1*La)^2 ...
-4*Jt1*La*(kb*kb*N+Ra*bt1))))/(kb*kb*N+Ra*bt1);

tau2 = (0.5*((Jt1*Ra+bt1*La) - sqrt((Jt1*Ra+bt1*La)^2 ...
-4*Jt1*La*(kb*kb*N+Ra*bt1))))/(kb*kb*N+Ra*bt1);
%%
%

tau11 = (0.5*((Jt2*Ra+bt2*La) + sqrt((Jt2*Ra+bt2*La)^2 ...
-4*Jt2*La*(kb*kb*N+Ra*bt2))))/(kb*kb*N+Ra*bt2);

tau21 = (0.5*((Jt2*Ra+bt2*La) - sqrt((Jt2*Ra+bt2*La)^2 ...
-4*Jt2*La*(kb*kb*N+Ra*bt2))))/(kb*kb*N+Ra*bt2);

%% inverter parameter
% inverter constant
fc = 1000; % frequency
taur = 1/(2*fc);
Vdc = 42; % supply voltage
Vc = 5;% peak of ref voltage
Kr = 0.65*Vdc/Vc; % Inverter gain

Hc = 8;
tauc1 = tau2;
tauc2 = tau21;
%% reduced current loop constant pitch
%K = tau1/(2*taur);
Kc1 = 0.5*tau1*tauc1/(taur*K1*Kr*Hc*taum1);
Kfi1 = Kc1*Kr*K1*Hc*taum1/tauc1;
KiEL = Kfi1/(Hc*(1 + Kfi1));
tau31 = tau1 + taur;
tauiEL =  tau31/(1+Kfi1);
%% reduced current loop constant yaw
Kc2 = 0.5*tau11*tauc1/(taur*K1*Kr*Hc*taum1);
Kfi2 = Kc2*Kr*K1*Hc*taum1/tauc2;
KiAZ = Kfi2/(Hc*(1 + Kfi2));
tau32 = tau11 + taur;
tauiAZ =  tau32/(1+Kfi2);

%% servo speed filter pitch
% KsEL = 6/(10*pi);
% tausEL = 0.0001;
KsEL = 10;
tausEL = 0.5;
%% servo speed filter yaw
% KsAZ = 6/(10*pi);
% tausAZ = 0.0001;
KsAZ = 40;
tausAZ = 0.5;
%% position sensor constant pitch
delD = 30.30; % length of receiver, cm
delP = 480; % length of image size in pixel
Kpixel = delD/delP; % pixel to cm conversion
lambda = 0.38; %3.8mm, focal length in cm
sx = 0.00056 ; %5.6um,pixel dimension in cm
sy = 0.00056; %5.6um,pixel dimension in cm
Cx = Kpixel*lambda/sx; %horizontal factor
Cy = Kpixel*lambda/sy; %vertical factor
CwEL = 0.0829;
CwAZ = 0.0829;



%% State-space model
% states x(t) = [fy omegaey iaEL iaEL* fx omegaez iaAZ iaAZ*]
% xdot(t) = Ax(t) + Bu
A = [0              Cy           0          0             0       0         0           0;
    -Kew/(Cy*Jey) -(Kef/Jey)   kb*N/Jey     0             0       0         0           0;
     0              0         -(1/tauiEL)   KiEL/tauiEL   0       0         0           0;
     0              0            0          -(1/tausEL)   0       0         0           0;
     0              0            0          0             0       Cx        0           0;
     0              0            0          0       -Kaw/(Cx*Ja) -(Kaf/Ja) kb*N/Ja     0;
     0              0            0          0             0       0        -(1/tauiAZ) KiAZ/tauiAZ;
     0              0            0          0             0       0         0          -(1/tausAZ)];
     
B = [0 0;0 0;0 0;(KsEL*CwEL)/tausEL 0;0 0;0 0;0 0;0 (KsAZ*CwAZ)/tausAZ] ;

G = [0          0           0        0   0   0 0 0;
     0         1/Jey        0        0   0   0 0 0;
     0           0          0        0   0   0 0 0;
     0           0          0        0   0   0 0 0;
     0           0          0        0   0   0 0 0;
     0           0          0        0   0  1/Ja 0 0;
     0           0          0        0   0   0 0 0;
     0           0          0        0   0   0 0 0];
 
 
C = [1 0 0 0 0 0 0 0; 0 0 0 0 1 0 0 0];

D = zeros(2,2);

Ap = A(1:4,1:4);
Bp = B(1:4)';
Cp = C(1:4);
Dp = 0;
Gp = G(1:4,2);

Ayaw = A(5:8,5:8);
Byaw = B(13:16)';
Cyaw = [C(10) C(12) C(14) C(16)];
Dyaw = 0;
Gyaw = G(5:8,6);

%% Stability, Controllability and Observability
% %Eigenvalues of the system
% eigen = eig(A)
% %Controllability Matrix
% Co=ctrb(A,B)
% % Number of uncontrollable states
% unco=length(A)-rank(Co)
% 
% % Observability Matrix
% Ob = obsv(A,C)
% % Number of unobservable states
% unob = length(A)-rank(Ob)
[eigenp,Cop, uncop,Obp,unobp]= chksys(Ap,Bp,Cp)
[eigeny,Coy, uncoy,Oby,unoby]= chksys(Ayaw,Byaw,Cyaw)
%% initial condition response

% x0 = [2.083 0 0 0 2.083 0 0 0]';
% sys = ss(A,[],C,[]);
% initial(sys,x0)
% step(ss(A,B,C,D))

%%

%[A,B,C,D]=tf2ss([1],[1 2]) %[1] or 1 is the same thing in this case
%u = [1 zeros(1,numel(t)-1)]; %impulse
%u = 15.15*ones(1,numel(t)); %step
%u = t; %ramp
%custom square input
ts = 0.005;
t = 0:ts:2;
u = [zeros(1,numel(t));zeros(1,numel(t))];
u (:,1.115/ts+1:1.38/ts+1) = 15.15;
up = u(1,:);uy = u(2,:);
xp0 = [2.083 0 0 0];
xy0 = [2.083 0 0 0]'; %initial condition of system states
[yp,xp] = lsim(Ap,Bp,Cp,Dp,up,t,xp0); %Simulate time response 
[yy,xy] = lsim(Ayaw,Byaw,Cyaw,Dyaw,uy,t,xy0); %Simulate time response 
load('sensoroutverificationrefined.mat');

figure(3)
plot(t,up,'--',sensorout(1,:),sensorout(2,:),'--',t,yp,'Linewidth',2);grid on
legend('Input','Experiment','Simulation')
xlabel 'Time (seconds)'; ylabel 'Vertical Position on White Screen (cm)';
title ('Vertical Position')

figure(4)
plot(t,uy,'--',sensorout(1,:),sensorout(3,:),'--',t,yy,'Linewidth',2);grid on
legend('Input','Experiment','Simulation')
xlabel 'Time (seconds)'; ylabel 'Horizontal Position on White Screen (cm)';
title ('Horizontal Position')

% r = sensorout(2,:)-y(:,1);                     % Residuals.
% normr = norm(r);
% SSE = normr.^2;              % Error sum of squares.
% TSS = norm(y(:,1)-mean(y(:,1)))^2;     % Total sum of squares.
% r2 = 1 - SSE/TSS;            % R-square statistic.
