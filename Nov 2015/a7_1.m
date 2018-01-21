%plot Fig. 6

clc
clear

%Multi SUs and Multi PUs all exponential distributed
%Finding Eigenvector and Eigenvalues 
%Making matrices A, B for 
%Given cj=j*c and M and N 
%Making initial Condition P(0)

% change of \rho by lambdaP


%this works!
%Individiual Buffer

x=0.1:.5:300;
Np=7; % # Producer (SUs)
Nc=2; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda
%Consumer (PU)
muCS=[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=2.14;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=1.03;       % SU ON period parameter  (Producing)
lambdaP=1.73;   % SU OFF period Parameter (NOT Producing)


c_c =3.52; % Each Consumer(primary)'s Channel capacity
c_p =pi/3;     % C0 is all the time available

epsi = 1e-5;
Epsi_Out=0.0201; % epsilon-outage



c_p_min=1e-3;
c_p_stp=0.05;
c_p_max=100;


t_stp=0.01; 

Tmax=1e2;


%-------------------------------------------------------------------------

R=[];
TSet=[];
L=[];
fl =0;    
for i=1:length(muCS)
    muC=muCS(i);
    disp(['muC= ', num2str(muC)])
    F2=@(x)0;
    T=[];
    RHO=[];
    c_p=c_p_min;
    rho=0;
    t=0;
    
    while(rho<1 && t< Tmax)
        
        disp(['rho= ', num2str(rho), ', c_p= ', num2str(c_p)])
        
        [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );             
        
        if (F2(t)<Epsi_Out)
            while (F2(t)<Epsi_Out && t>0)
                t=t-t_stp;
                
            end
        else
            while (F2(t)>Epsi_Out)
                t=t+t_stp;
                
            end
        end

        RHO=[RHO, rho];
        T=[T t];
        c_p=c_p+c_p_stp;
        
        t1=Np*c_p*lambdaP/(lambdaP+muP);
        t2=c_c*Nc*lambdaC/(lambdaC+muC);
        rho=t1/t2;
        
    end
    R=[R;RHO];
    TSet=[TSet; T];
    L=[L;'\fontname{times}\mu_c= '];

    plot(T, RHO)
    hold on
end   

%plot(TSet, R)

ylabel(['\fontname{times}Maximum sustainable Stability Ratio'])
xlabel(['\fontname{times}Delay Threshod (s)'])
legend([L, num2str(muCS')])
grid on
hold off
axis square
