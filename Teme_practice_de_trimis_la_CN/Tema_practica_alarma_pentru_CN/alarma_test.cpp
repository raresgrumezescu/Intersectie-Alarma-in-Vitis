#include <iostream>
#include <ap_int.h>
#include "alarma.h"

// Pe baza celor doua modele pe care le-ati lucrat la cursul practic din 11 Noiembrie,
// si anume: "functii_inline", respectiv "sapte_segmente", am elaborat urmatoarea rezolvare
// pentru Problema Alarmei, pe care ne-ati dat-o ca tema la curs.

// consider mai multi registrii de 16 biti penrtu fiecare caz cand cate un senzor se activeaza,
// sau cand codul este inserat corect.

// bitii indexati cu 15, 14, 13, 12 reprezinta bitii pe care se retine codul alarmei,
// bitii indexati cu 6 si 7 sunt bitii corespunzatori senzorilor de miscare
// bitii indexati cu 2, 1 si 0 sunt bitii corespunzatori senzorilor de la ferestre

// restul bitilor nu sunt folositi

// vectorul de input-uri alcatuit din secvente de cae 16 biti cu semnificatia precizata mai sus
ap_uint<16> registrii[6] = {
		0b1011000010000000,
		0b1010000010000000,
		0b1001000001000000,
		0b1010000000000100,
		0b1010000000000010,
		0b1010000000000001
};

// urmatorii trei vectori reprezinta combinatiile de biti 1/0 cu semnificatia stins/aprins,
// primul bit din secventa (citita de la stanga la dreapta) este decimal point-ul

// output pentru al treilea bec indicator 7segmente
ap_uint<8> rezultat7segmente3[6] = {
		0b11111111,
		0b10000110,
		0b10000110,
		0b10000110,
		0b10000110,
		0b10000110
};

// output pentru al doilea bec indicator 7segmente
ap_uint<8> rezultat7segmente2[6] = {
		0b11000000,
		0b10100100,
		0b11111001,
		0b11000000,
		0b11000000,
		0b11000000
};

// output pentru primul bec indicator 7segmente
ap_uint<8> rezultat7segmente1[6] = {
		0b10101011,
		0b11000000,
		0b11000000,
		0b10110000,
		0b10100100,
		0b11111001
};

int main() {
	int status = 0;

	ap_uint<8> segment1;
	ap_uint<8> segment2;
	ap_uint<8> segment3;

	// in newRegister salvez valoarea registrului in care campul de alarma se modifica,
	// adica atunci cand unul din senzori se activeaza, alarma se activeaza.
	// Echivalent cu "codul de activare a fost inserat corect".
	ap_uint<16> newRegister;
	ap_uint<16> registru = 0b1010000010000000;

	for (int i = 0; i < 6; i++) {
		alarma(registrii[i], &segment1, &segment2, &segment3, &newRegister);
		std::cout << "Noul registru este : " << newRegister << "   Registrul initial este : " << registrii[i] << "         Cod bec3 este : " << segment3 << "  7segmente asteptat : " << rezultat7segmente3[i] << "        Cod bec2 este : " << segment2 << "  7segmente asteptat : " << rezultat7segmente2[i] << "        Cod bec1 este : " << segment1 << "  7segmente asteptat : " << rezultat7segmente1[i] << std::endl;
		if (segment3 != rezultat7segmente3[i] || segment2 != rezultat7segmente2[i] || segment1 != rezultat7segmente1[i]) {
			status = -1;
			break;
		}
	}

	if (status == 0)
			std::cout << "Test trecut cu succes !" << std::endl;
	else
			std::cout << "Test FAILED !" << std::endl;


	return status;
}
