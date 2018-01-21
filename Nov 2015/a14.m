clc
clear

%Finding Eigenvector and Eigenvalues
%Making D, M
% Different number of Users

disp(['Single channel Multiple SUs'])
N=3;

c_p=1; % traffic generation rate
c_c=1.3; % Channel capacity
lambda=1.2; % ON period parameter
mu=0.5;   % OFF period Parameter

epsi = 1e-2;

X1=0.0;
DX=.1;
X2=4;
x=X1:DX:X2;

M=zeros(N+1, N+1);

disp(['stability number= ', num2str(N*c_p*mu/(c_c*(lambda+mu)))])
if (N*mu*c_p/(c_c*(lambda+mu))>1)
disp(['System is Unstable'])
break
end

for i=0:N
for j=0:N
   if (j==i+1) 
    M(i+1,j+1)= (i+1)*lambda;
   elseif(j==i)
    M(i+1,j+1)= -((N-i)*mu+i * lambda);
   elseif(j==i-1)
    M(i+1,j+1)= (N-i+1)*mu;
   end

end
end

d=(0:N)*c_p;
d=d-c_c*ones(1,N+1);
D=diag(d);

[V, G]=eig(D^-1*M);

%Scale factor
for i=1:N+1
if(G(i,i)<-epsi)
    S(i)=1/V(N+1,i);
else
    S(i)=1;
end
end
V=V*diag(S);
% finding negative eigen values
I=[];
for i=0:N
if (G(i+1,i+1) < - epsi)
    I=[I i+1];
end
end

a=zeros(1, length(I));
b=zeros(1, N+1); % coefficients 1* (N+1)
for j=1:length(I)
t=1;
for i=1:length(I)
    if (i~=j)

        t=t*G(I(i),I(i))/(G(I(i),I(i))-G(I(j),I(j)));
    end
end
a(j)=-(mu/(lambda+mu))^N *t;
b(I(j))=-(mu/(lambda+mu))^N *t;
end

%diag(G)'
%b

In0=(0:N)';

F_inf=1/(lambda+mu)^N .*factorial(N)./factorial(N-In0)./factorial(In0)...
.*mu.^In0.*lambda.^(N-In0);

F=diag(F_inf)*ones(N+1,length(x));
G1=0;
for i=1:length(I)
F=F+a(i)*V(:,I(i))*exp(G(I(i),I(i))*x);
G1=G1-a(i)*V(:,I(i))*exp(G(I(i),I(i))*x);

end
G2=@(x)-sum(b.*sum(V).*exp(diag(G)'*x));

disp(['z= ', num2str(sort(diag(G))')])

subplot(131)
plot(x,log10(abs(sum(G1))))
title(['\rho= ', num2str(N*mu/(c_c*(lambda+mu)))])
xlabel(['buffer size'])
ylabel(['Log(overflow probability)'])
grid on


subplot(132)
plot(x,(abs(sum(G1))))
title(['\rho= ', num2str(N*mu/(c_c*(lambda+mu)))])
xlabel(['buffer size'])
ylabel(['Overflow probability'])
grid on



%------------------------------------

%Consumer- Producer model

disp(['Consumer- Producer model'])

Pcon=0.99999;

muC=1/Pcon;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1/(1-Pcon);       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=lambda;       % SU OFF period parameter
lambdaP=mu;   % SU ON period Parameter 

Nc=1; % Number of Consumers
Np=N; % Number of Producers

c_c=c_c; % Consumer channel Capacity
c_p=c_p; % Producer Channel Capacity

[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp A B]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

r4=Np*(Np*c_p*lambdaP-c_c*(muP+lambdaP))/(c_c*(Np*c_p-c_c));
r5=Np*(Np*c_p*lambdaP-c_c*(muP+lambdaP))/(c_c*(Np*c_p-c_c));

r6= N*(c_c * mu +c_c -N*mu)/(c_c*(c_c-N));


r7= Np*(c_c * lambdaP +c_c -N*lambdaP)/(c_c*(c_c-N));


disp(['z0= ', num2str(z0)])
disp(['r4= ', num2str(r4)])
disp(['z= ', num2str(sort(z))])


EB=@(epsi,q)[(Np*c_c*(muP+lambdaP)+c_c^2*log(epsi)/q)/(Np*(Np*lambdaP-c_c* log(epsi)/q));...
    c_c*(muP+lambdaP)/(Np * lambdaP)];

QB=[];
q_min=1;
q_stp=0.5;
q_max=1000;


for q=q_min:q_stp:q_max
    
    b=EB(epsi, q);

    QB=[QB b];

end




subplot(131)
hold on
plot(x,log10(abs(F1(x))), 'r.')
xlabel(['buffer size'])
ylabel(['Log(overflow probability)'])
grid on


subplot(132)
plot(q_min:q_stp:q_max,QB);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
title(['Single channel Multiple SUs'])
legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis square
