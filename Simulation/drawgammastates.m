%% Vertical and Horizontal Position
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state1 = plot(timeinterval{1},vertpos{1},'-',timeinterval{6},vertpos{6},'--',timeinterval{11},vertpos{11},'--x',timeinterval{16},vertpos{16},'--.',timeinterval{21},vertpos{21},':');
grid on;
set(state1,'LineWidth', 3,'MarkerSize',3);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Vertical Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.05','\gamma=0.10','\gamma=0.15','\gamma=0.20')

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state7 = plot(timeinterval{1},horzpos{1},'-',timeinterval{31},horzpos{31},'--',timeinterval{56},horzpos{56},'--x',timeinterval{81},horzpos{81},'--.',timeinterval{101},horzpos{101},':');
grid on;
set(state7,'LineWidth', 3,'MarkerSize',3 );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Horizontal Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.30','\gamma=0.50','\gamma=0.80','\gamma=1.00')

%% Pointing Error
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state1 = plot(timeinterval{1},verterr{1},'-',timeinterval{6},verterr{6},'--',timeinterval{11},verterr{11},'--x',timeinterval{16},verterr{16},'--.',timeinterval{21},verterr{21},':');
grid on;
set(state1,'LineWidth', 2,'MarkerSize',3);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Vertical Position Error(cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.05','\gamma=0.10','\gamma=0.15','\gamma=0.20')

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state7 = plot(timeinterval{1},horzerr{1},'-',timeinterval{31},horzerr{31},'--',timeinterval{56},horzerr{56},'--x',timeinterval{81},horzerr{81},'--.',timeinterval{101},horzerr{101},':');
grid on;
set(state7,'LineWidth', 2,'MarkerSize',3 );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Horizontal Position Error (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.30','\gamma=0.50','\gamma=0.80','\gamma=1.00')

%% angular velocity
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state1 = plot(timeinterval{1},vertvel{1},'-',timeinterval{6},vertvel{6},'--',timeinterval{11},vertvel{11},'--x',timeinterval{16},vertvel{16},'--.',timeinterval{21},vertvel{21},':');
grid on;
set(state1,'LineWidth', 2);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Pitch Angular Velocity  \omega_{ey} (rad/s)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.05','\gamma=0.10','\gamma=0.15','\gamma=0.20')

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state7 = plot(timeinterval{1},horzvel{1},'-',timeinterval{31},horzvel{31},'--',timeinterval{56},horzvel{56},'--x',timeinterval{81},horzvel{81},'--.',timeinterval{101},horzvel{101},':');
grid on;
set(state7,'LineWidth', 2);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Yaw Angular Velocity  \omega_{ez} (rad/s)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.30','\gamma=0.50','\gamma=0.80','\gamma=1.00')
%% control action
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state1 = plot(timeinterval{1},vertcontrol{1},'-',timeinterval{6},vertcontrol{6},'--',timeinterval{11},vertcontrol{11},'--x',timeinterval{16},vertcontrol{16},'--.',timeinterval{21},vertcontrol{21},':');
grid on;
set(state1,'LineWidth', 2);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Pitch Control Action', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.05','\gamma=0.10','\gamma=0.15','\gamma=0.20')

figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);

state7 = plot(timeinterval{1},horzcontrol{1},'-',timeinterval{31},horzcontrol{31},'--',timeinterval{56},horzcontrol{56},'--x',timeinterval{81},horzcontrol{81},'--.',timeinterval{101},horzcontrol{101},':');
grid on;
set(state7,'LineWidth', 2);

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Yaw Control Action', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
legend('\gamma=0.00','\gamma=0.30','\gamma=0.50','\gamma=0.80','\gamma=1.00')

%% Pointing error norm and sd

gam = 0:0.01:1;
figure (13)
plot(gam,rmse1,'--o',gam,rmse2,'--x','Linewidth', 2); grid on
legend('Vertical Root Mean Squared Pointing Error','Horizontal Root Mean Squared Pointing Error');
xlabel '\gamma'
ylabel 'Root Mean Squared Pointing Error'

figure (14)
plot(gam,sde1,'--o',gam,sde2,'--x','Linewidth', 2); grid on
legend('Vertical Error SD','Horizontal Error SD');
xlabel '\gamma'
ylabel 'Standard Deviation of Pointing Error'
