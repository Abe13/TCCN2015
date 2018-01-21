function p=Pout1(c_p, q, muC, lambdaC ,  c_c)

p=muC/(muC+lambdaC)*c_c/(c_c-c_p)*exp(-(lambdaC/c_p-muC/(c_c-c_p))*q);

