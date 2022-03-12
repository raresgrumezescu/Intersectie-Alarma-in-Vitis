#include <ap_int.h>

void alarma(ap_uint<16> registru, ap_uint<8> *segment1, ap_uint<8> *segment2, ap_uint<8> *segment3, ap_uint<16> *newRegister) {
#pragma HLS INTERFACE ap_none port=segment3
#pragma HLS INTERFACE ap_none port=segment2
#pragma HLS INTERFACE ap_none port=newRegister

#pragma HLS INTERFACE ap_none port=segment1
#pragma HLS INTERFACE ap_none port=registru
#pragma HLS INTERFACE ap_ctrl_none port=return

	ap_uint<4> alarma = 0b0000;
	alarma[0] = registru[12];
	alarma[1] = registru[13];
	alarma[2] = registru[14];
	alarma[3] = registru[15];

	// codul a fost inserat corect, alarma se va activa (se va afisa 'ON', prescurtare de la OPEN)
	// trebuie facuta mentiunea ca acest "ON" nu are semnificatia celui din enuntul de pe MS Teams,
	// care inseamna ca alarma este dezactivata. "ON"-ul afisat vine de la prima si ultima litera din
	// "OPEN", care sugereaza ca alarma este activata.
	if (alarma == 0b1011) {
		*segment3 = 0b11111111; // nefolosit
		*segment2 = 0b11000000; // litera '0'
		*segment1 = 0b10101011; // litera 'n'
		*newRegister = 0b0000000000000000;
		// se copie "registru" in "newRegister" nemodificat, deoarece parola este corecta
		*newRegister = registru;
		return;
	} else {
		// Folosind conventiile:
		// - SW1 activ => se afiseaza codul "E01"
		// - SW2 activ => se afiseaza codul "E02"
		// - SW3 activ => se afiseaza codul "E03"
		// - SW6 activ => se afiseaza codul "E10"
		// - SW7 activ => se afiseaza codul "E20"

		// Aceste conventii le-am stabilit pe baza conventiilor propuse de dumneavoastra la cursul
		// practic, cu mentiunea ca au fost putin adaptate ca sa se poata afisa folosind 3 7segmente.

		// logica este aceeasi pentru toate if-urile care urmeaza:
		// se verifica daca bitul dinregostru corespunzator senzorului curent este 1.
		// In caz afirmativ, se afiseaza codul de problema pe cele 3 7segmente
		// si se salveaza in newRegsiter continutul noului registru, cu SW15, SW14, SW13, SW12
		// modificate sa contina codul alarmei.
		if (registru[6] == 0b1) {
			*segment3 = 0b10000110; // litera 'E'
			*segment2 = 0b11111001; // cifra '1'
			*segment1 = 0b11000000; // cifra '0'
			*newRegister = 0b0000000000000000;
			// se seteaza parola
			registru[15] = 1;
			registru[14] = 1;
			registru[13] = 0;
			registru[12] = 1;
			*newRegister = registru;
			return;
		}
		if (registru[7] == 0b1) {
			*segment3 = 0b10000110; // litera 'E'
			*segment2 = 0b10100100; // cifra '2'
			*segment1 = 0b11000000; // cifra '0'
			*newRegister = 0b0000000000000000;
			// se seteaza parola
			registru[15] = 1;
			registru[14] = 1;
			registru[13] = 0;
			registru[12] = 1;
			*newRegister = registru;
			return;
		}
		if (registru[0] == 0b1) {
			*segment3 = 0b10000110; // litera 'E'
			*segment2 = 0b11000000; // cifra '0'
			*segment1 = 0b11111001; // cifra '1'
			*newRegister = 0b0000000000000000;
			// se seteaza parola
			registru[15] = 1;
			registru[14] = 1;
			registru[13] = 0;
			registru[12] = 1;
			*newRegister = registru;
			return;
		}
		if (registru[1] == 0b1) {
			*segment3 = 0b10000110; // litera 'E'
			*segment2 = 0b11000000; // cifra '0'
			*segment1 = 0b10100100; // cifra '2'
			*newRegister = 0b0000000000000000;
			// se seteaza parola
			registru[15] = 1;
			registru[14] = 1;
			registru[13] = 0;
			registru[12] = 1;
			*newRegister = registru;
			return;
		}
		if (registru[2] == 0b1) {
			*segment3 = 0b10000110; // litera 'E'
			*segment2 = 0b11000000; // cifra '0'
			*segment1 = 0b10110000; // cifra '3'
			*newRegister = 0b0000000000000000;
			// se seteaza parola
			registru[15] = 1;
			registru[14] = 1;
			registru[13] = 0;
			registru[12] = 1;
			*newRegister = registru;
			return;
		}
	}
}
