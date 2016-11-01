clear all;
clc;

filename   = 'linea.csv'; 
Points     = csvread(filename,0,0);

x = Points(:,1);
y = Points(:,2);
Coord = [x y];
xgrid = [10 20];
ygrid = [20 40];
C = zeros(40,40);
cont = 1;
cont2 = 0;
for i=1:size(C)
   for j =1:size(C)
    if(mod(cont2,2)==0)    
      if(mod(cont,2) == 0)
        C(i,j) = 255;
      else
        C(i,j) = 22;    
      end
    else
      if(mod(cont,2) == 0)
        C(i,j) = 22;
      else
        C(i,j) = 255;    
      end  
    end
   cont = cont+1;
   end
   cont2 = cont2+1;
end

 for i = 1:size(x)
  C(Coord(i,1),Coord(i,2)) = 50;     
 end
 
xline = 20:1:30;
yline = ((18-10)/(30-20))*xline + (18-((18-10)/(30-20))*30);
im = image(C)
hold on
plot(yline,xline,'k','LineWidth',2);
im.AlphaData = 0.5;
grid on
