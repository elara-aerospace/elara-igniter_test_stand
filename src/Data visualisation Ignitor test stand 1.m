function monitorPressureSensors()
    % Serial port object 
    arduinoObj = serialport('COM3', 9600); % Important: Change the COM port according to your connection

    % Real-time plots:
    figure;
    subplot(4, 1, 1);
    h1 = animatedline;
    title('N2 Pressure');
    ylabel('Voltage');

    subplot(4, 1, 2);
    h2 = animatedline;
    title('O2 Pressure');
    ylabel('Voltage');

    subplot(4, 1, 3);
    h3 = animatedline;
    title('CH4 Pressure');
    ylabel('Voltage');

    subplot(4, 1, 4);
    h4 = animatedline;
    title('Igniter Pressure');
    ylabel('Voltage');
    xlabel('Time');

    % Infinite loop to keep reading and plotting data
    while true
        if arduinoObj.NumBytesAvailable > 0
            data = readline(arduinoObj);
            if contains(data, 'Pressures:')
                % Parse the incoming data
                pressureData = sscanf(data, 'Pressures: N2 = %f, O2 = %f, CH4 = %f, Igniter = %f');
                
                % Get current time
                t = datetime('now');

                % Update plots
                addpoints(h1, t, pressureData(1));
                addpoints(h2, t, pressureData(2));
                addpoints(h3, t, pressureData(3));
                addpoints(h4, t, pressureData(4));

                % Refresh plots
                drawnow;
            elseif contains(data, 'Safety Shutdown')
                disp('Safety shutdown initiated!');
            end
        end
    end
end