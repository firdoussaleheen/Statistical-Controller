%% Parameters of Gimbaled Laser Target System
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
tausEL = 1/192;
%% servo speed filter yaw
% KsAZ = 6/(10*pi);
% tausAZ = 0.0001;
KsAZ = 40;
tausAZ = 1/192;
%% position sensor constant pitch
delD = 30.30; % length of receiver, cm
delP = 480; % length of image size in pixel
Kpixel = delD/delP; % pixel to cm conversion
lambda = 0.38; %3.8mm, focal length in cm
sx = 0.00056 ; %5.6um,pixel dimension in cm
sy = 0.00056; %5.6um,pixel dimension in cm
Cx = 2.4*Kpixel*lambda/sx; %horizontal factor
Cy = 2.2*Kpixel*lambda/sy; %vertical factor
% CwEL = 0.0829;
% CwAZ = 0.0829;
% CwEL = 1;
% CwAZ = 1;
CwEL = 0.00198;
CwAZ = 0.00198;


