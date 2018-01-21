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
Np=1; % # Producer (SUs)
Nc=2; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda
%Consumer (PU)
muCS=[.59191];   % PU OFF period Parameter (Consuming)
lambdaC=2.14;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=1.03;       % SU ON period parameter  (Producing)
lambdaP=1.73;   % SU OFF period Parameter (NOT Producing)


c_c =3.52; % Each Consumer(primary)'s Channel capacity
c_p =pi/3;     % C0 is all the time available

epsi = 1e-5;
Epsi_Out=0.0201; % epsilon-outage

minC=0.1;


rho_min=1e-3;
rho_stp1=0.008;
rho_stp2=0.001;


q_stp=0.01; 

qmax=1e3;


%-------------------------------------------------------------------------

R=[];
QSet=[];
L=[];
fl =0;    
for i=1:length(muCS)
    muC=muCS(i);
    disp(['muC= ', num2str(muC)])
    F1=@(x)0;
    Q=[];
    RHO=[];

    rho=rho_min;
    q=0;

    t2=c_c*Nc*lambdaC/(lambdaC+muC);
    c_p=rho*t2/(Np*lambdaP/(lambdaP+muP));
    
       
    while(rho<1 && q< qmax)
        

        
        [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp A B]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c );             
        ch=sort(abs(diag(A)));
        if min(ch(2:(Np+1)*(Nc+1))) > minC

            if (F1(q)<Epsi_Out)
                while (F1(q)<Epsi_Out && q>0)
                    q=q-q_stp;

                end
            else
                while (F1(q)>Epsi_Out)
                    q=q+q_stp;

                end
            end
            
            disp(['rho= ', num2str(rho), ', c_p= ', num2str(c_p)])
            RHO=[RHO, rho];
            Q=[Q q];
            rho=rho+rho_stp1;
            
        else
            rho=rho+rho_stp2;
        end
        
        
        t2=c_c*Nc*lambdaC/(lambdaC+muC);
        c_p=rho*t2/(Np*lambdaP/(lambdaP+muP));
        
    end
    R(i).RHO=RHO;
    QSet(i).Q=Q;
    L=[L;'\fontname{times}\mu_c= '];

    plot(Q, RHO)
    hold on
end   

%plot(TSet, R)

ylabel(['\fontname{times}Maximum sustainable Stability Ratio'])
xlabel(['\fontname{times}Delay Threshod (s)'])
legend([L, num2str(muCS')])
grid on
hold off
axis square
