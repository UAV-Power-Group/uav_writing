clear all;
close all;

f = ballw(10)
% image(f.cdata)


%仅演示实时动画的调试格式为ballw(K)
%既演示实时动画又拍摄照片的调试格式为f = ballw(K,ki)
%K红球运动的循环次数（不小于1）
%ki指定拍摄照片的瞬间，取1到1034之间的任意整数
%f存储拍摄的照片数据，可用image(f.cdata)观察照片
%产生封闭的运动轨迹
function f = ballw( K,ki )
    data = importdata('test.csv');
    frame_no = data(:,1);
    x = data(:, 2);
    y = data(:, 3);
    z = data(:, 4);
    plot3(x, y, z, 'b','Linewidth',2)
    % x轴
    xlabel('x轴'); 
    % y轴
    ylabel('y轴'); 
    % z轴
    zlabel('z轴'); 

    title("UAV轨迹")

    h = line('Color',[1 0 0],'Marker','.','MarkerSize',30,'EraseMode','xor');
    %使小球运动
    n = length(x);
    i = 1;
    j = 1;
    while 1
        set(h,'xdata',x(i),'ydata',y(i),'zdata',z(i));
        %bw = [x(i),y(i),z(i)]     %查看小球位置
        drawnow;                    %刷新屏幕
        pause(0.001)               %控制球速
        i = i+1;
        if nargin == 2 && nargout == 1  %当输入变量个数为2并且输出变量1个时才拍摄照片
            if (i == ki && j == 1)
                f = getframe(gcf);      %拍摄i = ki时的照片
            end
        end
        if i > n
            i = 1;
            j = j+1;
            if j > K
                break;
            end
        end
    end
end
