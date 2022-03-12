#include "intersectie.h"
#include <iostream>

// Pe baza celor doua modele pe care le-ati lucrat la cursul practic din 11 Noiembrie,
// si anume: "functii_inline", respectiv "sapte_segmente", am elaborat urmatoarea rezolvare
// pentru Problema Intersectiei, pe care ne-ati dat-o ca tema la curs.

// vectorul de input-uri, unde fiecare element din el este alcatuit din informatiile din primele 4
// coloane ale tabelului dupa care ne-ati spus sa ne ghidam (Stg, D, S, J)
ap_uint<4> directions[16] = {
		0b0000,
		0b0001,
		0b0010,
		0b0011,
		0b0100,
		0b0101,
		0b0110,
		0b0111,
		0b1000,
		0b1001,
		0b1010,
		0b1011,
		0b1100,
		0b1101,
		0b1110,
		0b1111
};

// vectorul de output-uri, unde fiecare element din el este alcatuit din informatiile din ultimele 2
// coloane ale aceluiasi tabel (EW, NS)
ap_uint<2> culoare[16] = {
		0b10,
		0b01,
		0b01,
		0b01,
		0b10,
		0b10,
		0b10,
		0b01,
		0b10,
		0b10,
		0b10,
		0b01,
		0b10,
		0b10,
		0b10,
		0b10
};

int main(){
	int status = 0;

	ap_uint<2> semaphores;

	// Bitii din direction[i] reprezinta o posibilitate de activare a senzorilor din sosea,
	// (Stg, D, S, J, in aceasta ordine),
	// in timp ce cei 2 biti din din semaphores reprezinta starea activ/oprit a semafoarelor
	// EW si NS, in aceasta ordine.

	for (int i = 0; i < 16; i++) {
		intersectie(directions[i], &semaphores);
		std::cout << "digit = " << i << "    valoare semafoare = " << semaphores << std::endl;
		if (semaphores != culoare[i]){
			status = -1;
			break;
		}
	}

	if (status == 0)
		std::cout << "Test trecut cu succes !" << std::endl;
	else
		std::cout << "Test FAILED !    " << status << std::endl;

	return status;
}
