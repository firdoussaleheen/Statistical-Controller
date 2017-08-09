%% Code Author: Firdous Saleheen -- f.saleheen@temple.edu
% no permission necessary for non-commercial use
% Date: 10/3/2013

clear all;
close all;
clc;
format shortg;
%% Load parameters and compute controller
run LoadParameters1
run LoadnCheckModel
clc
[nx ny] = size(Gp);
[mx my] = size(Cp);
W = (1e-4)*eye(ny);
V = (1e-5)*eye(mx);
% compute Kalman Filtere Gain
Kpf =  KalmanFilter(Ap,Bp,Cp,Dp,Gp,W,V);
Kyf =  KalmanFilter(Ayaw, Byaw, Cyaw, Dyaw, Gyaw, W, V);

% compute state feedback gain using MCV
gamma = 2.0;
Kpmcv  = MCVController(Ap,Bp,Cp,Dp,Gp,W,gamma);
Kymcv = MCVController(Ayaw,Byaw,Cyaw,Dyaw,Gyaw,W,gamma);

%%

% open_system('image_processing_system.mdl');
% open_system('dSPACE_SIMULINK_INIT_2X.mdl');
% open_system('dSPACE_SIMULINK_MCV_2X.mdl');
