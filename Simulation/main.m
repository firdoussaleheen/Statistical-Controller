%% Code Author: Firdous Saleheen -- f.saleheen@temple.edu
% no permission necessary for non-commercial use
% Date: 7/27/2013
clear all;
close all;
clc;
format shortg

disp('start')
run LoadParameters1
run LoadnCheckModel

%% PID controller
% W = 1e-3;
% stoptime = 200;% seconds
% dt = 0.0001;
% runs = 1;
% tic
% [avgstatespid, timepid] = simStatesPID(stoptime, dt, runs,W);
% toc
% run piddrawing

%% LQG controller

% [Kplqg, elqg1] = LQGController(Ap,Bp,Cp,Dp);
% [Kylqg, elqg2] = LQGController(Ayaw,Byaw,Cyaw,Dyaw);
% 
% %[Ahat,Bhat,Chat,Dhat,Khat] = buildServo(A,B,C,D,G,Klqg);
% 
% Ahat = Ap-Bp*Kplqg;
% Bhat = [Bp Gp];
% Chat = eye(4,4);
% Dhat = zeros(4,2);
% Khat = Kplqg;
% 
% Ahat1 = Ayaw-Byaw*Kylqg;
% Bhat1 = [Byaw Gyaw];
% Chat1 = eye(4,4);
% Dhat1 = zeros(4,2);
% Khat1 = Kylqg;
% 
% W = 1e-3;
% stoptime = 10;% seconds
% dt = 0.0001;
% runs = 1;
% simName = {'ltslqgservo'};
% [avgstateslqg, timelqg] = simStates(stoptime, dt, runs,W,simName);

%% MCV Controller


% for ii = 1:23 
% %ii = 1;
% display(ii)
% W = 1e-3;
% stoptime = 5;%second
% dt = 0.0001;
% runs = 100;
% %round(100*sum(clock))
% %simName = {'ltsmcvservo'};
% gamma = 0.01*(ii-1);
% %gamma = 0.05;
% [Kpmcv, emcv1] = MCVController(Ap,Bp,Cp,Dp,Gp,W,gamma);
% Ahat = Ap-Bp*Kpmcv;
% Bhat = [Bp Gp];
% Chat = eye(4,4);
% Dhat = zeros(4,2);
% Khat = Kpmcv;
% 
% %gamma = 0.01;
% [Kymcv, emcv2] = MCVController(Ayaw,Byaw,Cyaw,Dyaw,Gyaw,W,gamma);
% Ahat1 = Ayaw-Byaw*Kymcv;
% Bhat1 = [Byaw Gyaw];
% Chat1 = eye(4,4);
% Dhat1 = zeros(4,2);
% Khat1 = Kymcv;
% 
% simName = {'ltslqgservo'};
% %[avgstateslqg, timelqg] = simStates(stoptime, dt, runs,W,simName);
% [avgstateslqg, timelqg] = simStates(runs,simName);
% vertrepeat{ii} = avgstateslqg(:,1);
% horzrepeat{ii} = avgstateslqg(:,7);
% vertrepeaterr{ii} = avgstateslqg(:,6);
% horzrepeaterr{ii} = avgstateslqg(:,12);
% 
%  rmse1(ii) = norm(vertrepeaterr{ii}(10000:end))/sqrt(length(vertrepeaterr{ii}(10000:end)));
%  sde1(ii)=std(vertrepeaterr{ii}(10000:end));
%  rmse2(ii) = norm(horzrepeaterr{ii}(10000:end))/sqrt(length(horzrepeaterr{ii}(10000:end)));
%  sde2(ii)=std(horzrepeaterr{ii}(10000:end));
% % 
% % % vertrepeaterrnorm(ii) = norm(avgstateslqg(:,6));
% % % horzpeaterrnorm(ii) = norm(avgstateslqg(:,12));
% % % vertrepeaterrsd(ii) = std(avgstateslqg(:,6));
% % % horzpeaterrsd(ii) = std(avgstateslqg(:,12));
% % 
% % %[avgstateslqg, timelqg] = simStates(stoptime, dt, runs,W,simName);
% % % emcvvert(ii)=min(real(emcv1));
% % % emcvhorz(ii)=min(real(emcv2));
% % % emcvvert1(ii)=max(real(emcv1));
% % % emcvhorz1(ii)=max(real(emcv2));
% % % 
% % % timeinterval{ii}=timelqg(:,1);
% % %  rmse1(ii) = norm(avgstateslqg(:,6))/sqrt(length(avgstateslqg(:,6)));
% % %  sde1(ii)=std(avgstateslqg(:,6));
% % 
% % 
% % % vertpos{ii}=avgstateslqg(:,1);
% % % vertposnorm(ii)=norm(avgstateslqg(:,1));
% % % verterr{ii}=avgstateslqg(:,6);
% % % vertvel{ii}=avgstateslqg(:,2);
% % % vertvelnorm(ii)=norm(avgstateslqg(:,2));
% % % vertcontrol{ii}=avgstateslqg(:,5);
% % % vertcontrolnorm(ii)=norm(avgstateslqg(:,5));
% % % 
% % %rmse2(ii) = norm(avgstateslqg(:,12))/sqrt(length(avgstateslqg(:,12)));
% % %sde2(ii)=std(avgstateslqg(:,12));
% % 
% % % horzpospos{ii}=avgstateslqg(:,7);
% % % horzposnorm(ii)=norm(avgstateslqg(:,7));
% % % horzerr{ii}=avgstateslqg(:,12);
% % % horzvel{ii}=avgstateslqg(:,8);
% % % horzvelnorm(ii)=norm(avgstateslqg(:,8));
% % % horzcontrol{ii}=avgstateslqg(:,11);
% % % horzcontrolnorm(ii)=norm(avgstateslqg(:,11));
% end

%%
% rmspe1 = rmse1;
% rmspe2 = rmse2;
% gam = 0.0:0.05:1;
% figure (10)
% plot(gam,rmspe1,'--o',gam,rmspe2,'--x','Linewidth', 2); grid on
% legend('Vertical Root Mean Squared Pointing Error','Horizontal Root Mean Squared Pointing Error');
% xlabel '\gamma'
% ylabel 'Root Mean Squared Pointing Error (cm)'
% 
% %gam = 0.2:0.2:2;
% figure (11)
% plot(gam,sde1,'--o',gam,sde2,'--x','Linewidth', 2); grid on
% legend('Vertical Error SD','Horizontal Error SD');
% xlabel '\gamma'
% ylabel 'Standard Deviation of Pointing Error (cm)'
%% output feedback simulation
% [nx ny] = size(Gp);
% [mx my] = size(Cp);
% W = (1e-4)*eye(ny);
% V = (1e-5)*eye(mx);
% Kpf =  KalmanFilter(Ap,Bp,Cp,Dp,Gp,W,V);
% Kyf =  KalmanFilter(Ayaw, Byaw, Cyaw, Dyaw, Gyaw, W, V);
% [Kplqg, elqg1] = LQGController(Ap,Bp,Cp,Dp);
% [Kylqg, elqg2] = LQGController(Ayaw,Byaw,Cyaw,Dyaw);
% %build an augmented model with r,w,v as inputs and
% % all the states and estimated error states are output
% % Apaug = [Ap-Bp*Kplqg Bp*Kplqg; zeros(4,4) Ap-Kf*Cp];
% % Bpaug = [Bp Gp zeros(4,1);zeros(4,1) Gp -Kf];
% % Cpaug = eye(8,8);
% % Dpaug = zeros(8,3);
% %build an augmented model with r,w,v as inputs and
% % all the states are output
% Apaug = [Ap -Bp*Kplqg; Kpf*Cp Ap-Kpf*Cp-Bp*Kplqg];
% Bpaug = [Bp Gp zeros(4,1);Bp zeros(4,1) Kpf];
% Cpaug = eye(8,8);
% Dpaug = zeros(8,3);
% %eig(Apaug)
% Ayaug = [Ayaw -Byaw*Kylqg; Kyf*Cyaw Ayaw-Kyf*Cyaw-Byaw*Kylqg];
% Byaug = [Byaw Gyaw zeros(4,1);Byaw zeros(4,1) Kyf];
% Cyaug = eye(8,8);
% Dyaug = zeros(8,3);

% stoptime=5;
% dt = 0.0001;
% simName = {'ltslqgkalmanservo'};
% runs = 1;
% [avgstateslqg, timelqg] = simStates(runs,simName);
%% output feedback mcv
[nx ny] = size(Gp);
[mx my] = size(Cp);
W = (1e-4)*eye(ny);
V = (1e-5)*eye(mx);
Kpf =  KalmanFilter(Ap,Bp,Cp,Dp,Gp,W,V);
Kyf =  KalmanFilter(Ayaw, Byaw, Cyaw, Dyaw, Gyaw, W, V);
% 
for ii=1:21
display(ii)
gamma = 0.05*(ii-1);
[Kpmcv, emcv1] = MCVController(Ap,Bp,Cp,Dp,Gp,W,gamma);
Apaug = [Ap -Bp*Kpmcv; Kpf*Cp Ap-Kpf*Cp-Bp*Kpmcv];
Bpaug = [Bp Gp zeros(4,1);Bp zeros(4,1) Kpf];
Cpaug = eye(8,8);
Dpaug = zeros(8,3);

[Kymcv, emcv2] = MCVController(Ayaw,Byaw,Cyaw,Dyaw,Gyaw,W,gamma);
Ayaug = [Ayaw -Byaw*Kymcv; Kyf*Cyaw Ayaw-Kyf*Cyaw-Byaw*Kymcv];
Byaug = [Byaw Gyaw zeros(4,1);Byaw zeros(4,1) Kyf];
Cyaug = eye(8,8);
Dyaug = zeros(8,3);

stoptime=5;
dt = 0.0001;
simName = {'ltslqgkalmanservo'};
runs = 100;
[avgstateslqg, timelqg] = simStates(runs,simName);

vertrepeat{ii} = avgstateslqg(:,1);
horzrepeat{ii} = avgstateslqg(:,12);
vertrepeaterr{ii} = avgstateslqg(:,10);
horzrepeaterr{ii} = avgstateslqg(:,21);

 rmse1(ii) = norm(vertrepeaterr{ii}(10000:end))/sqrt(length(vertrepeaterr{ii}(10000:end)));
 sde1(ii)=std(vertrepeaterr{ii}(10000:end));
 rmse2(ii) = norm(horzrepeaterr{ii}(10000:end))/sqrt(length(horzrepeaterr{ii}(10000:end)));
 sde2(ii)=std(horzrepeaterr{ii}(10000:end));

% timeinterval{ii}=timelqg(:,1);
% rmse1(ii) = norm(avgstateslqg(:,10))/sqrt(length(avgstateslqg(:,10)));
% sde1(ii)=std(avgstateslqg(:,10));
% 
% vertpos{ii}=avgstateslqg(:,1);
% % vertposnorm(ii)=norm(avgstateslqg(:,1));
% verterr{ii}=avgstateslqg(:,10);
% vertvel{ii}=avgstateslqg(:,2);
% % vertvelnorm(ii)=norm(avgstateslqg(:,2));
% vertcontrol{ii}=avgstateslqg(:,11);
% % vertcontrolnorm(ii)=norm(avgstateslqg(:,5));
% % 
% rmse2(ii) = norm(avgstateslqg(:,21))/sqrt(length(avgstateslqg(:,21)));
% sde2(ii)=std(avgstateslqg(:,21));
% % %sde2(ii) = sqrt((avgstateslqg(:,12).*avgstateslqg(:,12))/length(avgstateslqg(:,12)) - sum((avgstateslqg(:,12))/length(avgstateslqg(:,12))));
% horzpos{ii}=avgstateslqg(:,12);
% % horzposnorm(ii)=norm(avgstateslqg(:,7));
% horzerr{ii}=avgstateslqg(:,21);
% horzvel{ii}=avgstateslqg(:,13);
% % horzvelnorm(ii)=norm(avgstateslqg(:,8));
% horzcontrol{ii}=avgstateslqg(:,22);
% % horzcontrolnorm(ii)=norm(avgstateslqg(:,11));
 end