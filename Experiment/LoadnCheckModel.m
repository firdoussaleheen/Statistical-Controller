%% State-space model
% states x(t) = [fy omegaey iaEL iaEL*][ fx omegaez iaAZ iaAZ*]
% xdot(t) = Ax(t) + Bu
Ap = [0              Cy           0          0            ;
    -Kew/(Cy*Jey) -(Kef/Jey)   kb*N/Jey     0            ;
     0              0         -(1/tauiEL)   KiEL/tauiEL  ;
     0              0            0          -(1/tausEL)] ;
                
Bp = [0 0 0 KsEL*CwEL/tausEL]';
Cp = [1 0 0 0];
Dp = 0;
Gp = [0      1/Jey    0           0]';                

Ayaw =[0            Cx        0           0;
     -Kaw/(Cx*Ja) -(Kaf/Jey) kb*N/Ja      0;
       0            0       -(1/tauiAZ) KiAZ/tauiAZ;
       0            0         0        -(1/tausAZ)];
     
Byaw = [0     0    0   KsAZ*CwAZ/tausAZ]' ;

Cyaw = [1 0 0 0];

Dyaw = 0;

Gyaw = [0      1/Ja    0           0]';

%% Stability, Controllability and Observability
[eigenp,Cop, uncop,Obp,unobp]= chksys(Ap,Bp,Cp);
[eigeny,Coy, uncoy,Oby,unoby]= chksys(Ayaw,Byaw,Cyaw);
