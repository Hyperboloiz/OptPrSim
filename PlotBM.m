clear ; close all; clc

fid = fopen( 'Path1.txt' , 'r' );
p1 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'TS1.txt' , 'r' );
TS1 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'Path2.txt' , 'r' );
p2 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'TS2.txt' , 'r' );
TS2 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'Path3.txt' , 'r' );
p3 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'TS3.txt' , 'r' );
TS3 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'Path4.txt' , 'r' );
p4 = fscanf( fid , "%f");
fclose(fid);

fid = fopen( 'TS4.txt' , 'r' );
TS4 = fscanf( fid , "%f");
fclose(fid);


plot(TS2, p2, 'rx','MarkerSize',5,'linestyle','-', 'color','r', ...
 TS3, p3, 'rx','MarkerSize',5,'linestyle','-', 'color','g',...
 TS4, p4, 'rx','MarkerSize',5,'linestyle','-', 'color','b');
legend( 'path2', 'path3','path4') ;
xlabel('time');
ylabel('GBM');
