%% Vertical and Horizontal Position
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
state1  = plot(timemcv(:,1),avgstatesmcv(:,1));
grid on;
set(state1                , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Vertical Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

subplot(2,1,2);
state5  = plot(timemcv(:,1),avgstatesmcv(:,6));
grid on;
set(state5                , ...
  'LineStyle'       , '-'        , ...
  'Color'           , 'bl'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Horizontal Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);
%% VELOCITY

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
state2  = plot(timemcv(:,1),avgstatesmcv(:,2));
grid on;
set(state2                , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('\omega_{ey} (rad per sec)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

subplot(2,1,2);
state6  = plot(timemcv(:,1),avgstatesmcv(:,7));
grid on;
set(state6                , ...
  'LineStyle'       , '-'        , ...
  'Color'           , 'b'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('\omega_{ez} (rad per sec)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);


%% CURRENT
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
state3  = plot(timemcv(:,1),avgstatesmcv(:,3));
grid on;
set(state3                , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Pitch Current (A)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

subplot(2,1,2);
state7  = plot(timemcv(:,1),avgstatesmcv(:,8));
grid on;
set(state7                , ...
  'LineStyle'       , '-'        , ...
  'Color'           , 'b'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Yaw Current (A)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

%% CURRENT COMMAND

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
state4  = plot(timemcv(:,1),avgstatesmcv(:,4));
grid on;
set(state4               , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Pitch motor current command i_{aEL}^* (A)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

subplot(2,1,2);
state4  = plot(timemcv(:,1),avgstatesmcv(:,9));
grid on;
set(state4               , ...
  'LineStyle'       , '-'        , ...
  'Color'           , 'b'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Yaw motor current command i_{aAZ}^* (A)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);
%% CONTROL Speed COMMAND

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
control1  = plot(timemcv(:,1),avgstatesmcv(:,5));
grid on;
set(control1               , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Pitch Speed Control Command \omega_{EL}^* (V)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);

subplot(2,1,2);
control2  = plot(timemcv(:,1),avgstatesmcv(:,10));
grid on;
set(state4               , ...
  'LineStyle'       , '-'        , ...
  'Color'           , 'b'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                    );
hYLabel = ylabel('Yaw Speed Control Command \oemga_{AZ}^* (V)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 16);