clc
clear


%------------------------------------

%Consumer- Producer model

disp(['Consumer- Producer model\n'])

disp(['Single SU Multiple channels'])

%Pcon=0.99999;

muC=1.6;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=0.7;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=0.3;       % SU OFF period parameter
lambdaP=0.4;   % SU ON period Parameter 

%Nc=5; % Number of Consumers
%Np=1; % Number of Producers

c_c=5.77; % Consumer channel Capacity
c_p=1; % Producer Channel Capacity


X1=0.0;
DX=.1;
X2=4;
x=X1:DX:X2;

epsi=1e-3;



%---------------------

epsi = 1e-3;
Epsi_Out=epsi; % epsilon-outage

minC=0.01;


rho_min=1e-3;
rho_stp1=0.008;
rho_stp2=0.001;


q_stp=0.01; 

qmax=1e2;

Nc_min=2;
Nc_max=20;

Np_min=2;
Np_max=10;

%-------------------------------------------------------------------------

theta=[];
for Nc=Nc_min:Nc_max
    for Np=Np_min:Np_max
        rho=RHO(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );
        
        if rho <1
            [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp A B]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );
        else
            z0=0;
        end
        
        theta(Nc,Np)=abs(z0);
    end
end

surf(Np_min:Np_max,Nc_min:Nc_max,  theta);

ylabel(['\fontname{times}Number of SUs'])
xlabel(['\fontname{times}Number of Channels'])
zlabel(['\fontname{times}Dominant Decay Rate'])
%title(['\fontname{times}Single SU Multiple channels'])
%legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis equal



