clc
close all
clear all
global dat
delete(instrfind);
dat = serial('COM5', 'BaudRate', 19200);
dat.InputBufferSize = 4096;
fopen(dat);
set(dat, 'ByteOrder', 'littleEndian'); 
disp 'Connection is ready!'
% disp 'Press "s" to start!'
total=[];
% cut_total=[];
% flag=0;
% indicator=[1 0 0; 0.850 0.325 0.098; 1 1 0; 0 1 0; ...
% 0 1 1; 0 0 1; 1 0 1];
% plot(0,0,'o','MarkerSize',72,'MarkerFaceColor',[1 1 1],'MarkerEdgeColor','none')


array_size = fread(dat,2,'uint8');
array_size = typecast(uint8([array_size(2), array_size(1)]), 'uint16');
for i=1:array_size        
      current=fread(dat,1,'uint8');
      total=[total current]
         
end

fclose(dat);
disp 'Connection is closed!'