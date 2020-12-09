fid = fopen( 'values.txt' , 'r' );
data = fscanf ( fid , '%f' );
fclose ( fid ) ;
[ vals , bins ] = hist ( data , 100 ) ;
plot ( bins , vals / trapz(bins, vals)  , '*', bins, 1/sqrt(2 * pi) ...
*exp(-bins .^2) /2 , '-' ) ;
legend( ' rejection sampling '  ) ;
xlim ([-5.0,5.0]);
ylim([0,0.5]);
xlabel ( 'x' ) ;
ylabel ( 'density' ) ;