% %%
% W = 0.01e-3;
% stoptime = 200;% seconds
% dt = 0.001;
% runs = 1;
% 
% [avgstatespid, timepid] = simStatesPID(stoptime, dt, runs,W);
%%
rmse1 = norm(15.15*ones(length(avgstatespid(:,1)),1)-avgstatespid(:,1))/sqrt(length(avgstatespid(:,1)));
figure('Units', 'pixels', ...
   'Position', [300 300 640 480]);
subplot(2,1,1);
state1  = plot(timepid(:,1),avgstatespid(:,1));
grid on;
set(state1                , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'r'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Vertical Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );
set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);
rmse2 = norm(15.15*ones(length(avgstatespid(:,2)),1)-avgstatespid(:,2))/sqrt(length(avgstatespid(:,2)));
subplot(2,1,2);
state2  = plot(timepid(:,1),avgstatespid(:,2));
grid on;
set(state2                , ...
  'LineStyle'       , '--'        , ...
  'Color'           , 'bl'        , ...
  'LineWidth'       , 2          );

hXLabel = xlabel('Time (second)' , 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                    );
hYLabel = ylabel('Horizontal Position (cm)', 'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12                      );


set(gca, ...
  'FontName'   , 'Times New Roman' ,...
  'FontSize'   , 12);

