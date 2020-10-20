clear all;
close all;

data = importdata('test.csv');
frame_no = data(:,1);
x = data(:, 2);
y = data(:, 3);
z = data(:, 4);
plot3(x, y, z)
% x轴
xlabel('x轴'); 
% y轴
ylabel('y轴'); 
% z轴
zlabel('z轴'); 

title("UAV轨迹")
 
