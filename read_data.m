clear all; clc;
data = importdata('theta_P_D_bias.txt');

time = data(:,1);
theta_dot = data(:,2);
theta = data(:,3);
subplot(3,1,1);
plot(time(1:500), theta(1:500));

subplot(3,1,2);
plot(time(1:500), theta_dot(1:500));


data_command = importdata('command_pd_bias.txt');

time_sp = data_command(:,1);
roll_sp = data_command(:,2);

for i = 2:length(time_sp)
    time_sp(i) = time_sp(i) - time_sp(1);
    roll_sp(i) = roll_sp(i);
end

time_sp(1) = 0;
subplot(3,1,3);
plot(time_sp, roll_sp);