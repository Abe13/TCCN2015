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
Np=3; % # Producer (SUs)
Nc=1; % # Consumer (PUs)



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


%Range of Maximum tolerable delay
T_max=1000;
T_stp=3;
T_min=0;



rho_0=0.001; %initial value for rho
rho_stp=0.00133; % rho step

%-------------------------------------------------------------------------
R=[];
L=[];
fl =0;    
for i=1:length(muCS)
    muC=muCS(i);
    F2=@(x)0;
    
    RHO=[];
    rho=rho_0;
    t1=Np*c_p*lambdaP/(lambdaP+muP);
    c_c=t1/rho/(Nc*lambdaC/(lambdaC+muC));
    
    for T=T_min:T_stp:T_max
        disp(T)
        
        while (F2(T)<Epsi_Out && rho<1)
            disp(['rho= ', num2str(rho),', F2(T)= ', num2str(F2(T))])
            
            t1=Np*c_p*lambdaP/(lambdaP+muP);
            c_c=t1/rho/(Nc*lambdaC/(lambdaC+muC));


            [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho_t fl]=Coef2(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );             
            rho=rho+rho_stp;
            
            while (fl==1)
                t1=Np*c_p*lambdaP/(lambdaP+muP);
                c_c=t1/rho/(Nc*lambdaC/(lambdaC+muC));


                [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho_t fl]=Coef2(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );             
                rho=rho+rho_stp;
            end

        end

        RHO=[RHO, rho-rho_stp];
    end
    R=[R;RHO];
    L=[L;'\fontname{times}\alpha= '];

end   

plot(T_min:T_stp:T_max, R)

ylabel(['\fontname{times}Maximum sustainable Stability Ratio'])
xlabel(['\fontname{times}Delay Threshod (s)'])
legend([L, num2str(muCS')])
grid on
hold off
axis square
