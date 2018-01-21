%%
clc
clear


%------------------------------------

%Consumer- Producer model

disp(['Consumer- Producer model\n'])

disp(['Single SU Multiple channels'])

Pcon=0.99999;

muCS=[1];%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=0.7;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=1/Pcon;       % SU OFF period parameter
lambdaP=1/(1-Pcon);   % SU ON period Parameter 

Nc=5; % Number of Consumers
Np=1; % Number of Producers

c_c=0.77; % Consumer channel Capacity
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
    Cp=[];

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
            Cp=[Cp, c_p];
            
            Q=[Q q];
            rho=rho+rho_stp1;
            
        else
            rho=rho+rho_stp2;
        end
        
        
        t2=c_c*Nc*lambdaC/(lambdaC+muC);
        c_p=rho*t2/(Np*lambdaP/(lambdaP+muP));
        
    end
    R(i).RHO=RHO;
    R(i).Cp=Cp;
    QSet(i).Q=Q;
    L=[L;'\fontname{times}\mu_c= '];

    %subplot(121)
    plot(Q, Cp)
    hold on
end   

%plot(TSet, R)

ylabel(['\fontname{times}Maximum sustainable Stability Ratio'])
xlabel(['\fontname{times}Delay Threshod (s)'])
title(['Single SU Multiple channels'])
legend([L, num2str(muCS')])
grid on
hold off
axis square





EB=@(epsi,q)[Nc/2*(c_c - (lambdaC+muC)*q/log(epsi)-sqrt((c_c - (lambdaC+muC)*q/log(epsi))^2 +4*c_c*lambdaC*q/log(epsi)));...
    Nc*c_c*lambdaC/(lambdaC+muC)];


QB=[];

for i=1:length(Q)
    q=Q(i);
    
    b=EB(epsi, q);
    QB=[QB b];

end






%subplot(121)

hold on
plot(Q,QB, 'r-.');
ylabel(['\fontname{times}Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
title(['\fontname{times}Single SU Multiple channels'])
legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis square



%-----------------------------------------------
%% Consumer- Producer model
clc
clear




%-----------------------------------------------
%Consumer- Producer model

disp(['Consumer- Producer model'])

disp(['Single Channel Multiple SUs'])

Pcon=0.99999;

muCS=1/Pcon;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1/(1-Pcon);       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=1.2;       % SU OFF period parameter
lambdaP=0.5;   % SU ON period Parameter 

Nc=1; % Number of Consumers
Np=3; % Number of Producers

c_c=1.3; % Consumer channel Capacity
c_p=1; % Producer Channel Capacity

%-----------------------
%---------------------

epsi = 1e-3;
Epsi_Out=epsi; % epsilon-outage

minC=0.01;


rho_min=1e-3;
rho_stp1=0.008;
rho_stp2=0.001;


q_stp=0.01; 

qmax=1e3;


%-------------------------------------------------------------------------

figure

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
    Cp=[];

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
            Cp=[Cp, c_p];
            
            Q=[Q q];
            rho=rho+rho_stp1;
            
        else
            rho=rho+rho_stp2;
        end
        
        
        t2=c_c*Nc*lambdaC/(lambdaC+muC);
        c_p=rho*t2/(Np*lambdaP/(lambdaP+muP));
        
    end
    R(i).RHO=RHO;
    R(i).Cp=Cp;
    QSet(i).Q=Q;
    L=[L;'\fontname{times}\mu_c= '];

    %subplot(122)
    plot(Q, Cp)
    hold on
    
    EB=@(epsi,q)[(Np*c_c*(muP+lambdaP)-c_c^2*log(epsi)/q)/(Np*(Np*lambdaP-c_c* log(epsi)/q));...
    c_c*(muP+lambdaP)/(Np * lambdaP)];

    QB=[];

    for i=1:length(Q)
        q=Q(i);

        b=EB(epsi, q);
        QB=[QB b];

    end






    %subplot(122)

    hold on
    plot(Q,QB, 'r-.');
    
end   

%plot(TSet, R)

ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
title(['Single channel Multiple SUs'])
legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis square



%-----------------------





