#include <ap_int.h>

void intersectie(ap_uint<4> directions, ap_uint<2> *semaphores) {
	#pragma HLS INTERFACE ap_none port=semaphores
	#pragma HLS INTERFACE ap_none port=directions
	#pragma HLS INTERFACE ap_ctrl_none port=return

	// problema se rezolva folosind un switch case, care asociaza fiecarei combinatii
	// de 4 biti, formata din 1 si 0, cate un cod corespunzator celor doua semafoare,
	// reprezentat de o secventa de 2 biti, formata din 1 si 0.

	// Pentru aceasta rezolvare am folosit abordarea cu switch-case pe care ne-ati aratat-o la cursul
	// practic din 11 Noiembrie, in cadrul celor doua probleme pe care le-ati rezolvat in Vitis.
	switch (directions){
					case 0b0000:
						*semaphores = 0b10;
						break;
					case 0b0001:
						*semaphores = 0b01;
						break;
					case 0b0010:
						*semaphores = 0b01;
						break;
					case 0b0011:
						*semaphores = 0b01;
						break;
					case 0b0100:
						*semaphores = 0b10;
						break;
					case 0b0101:
						*semaphores = 0b10;
						break;
					case 0b0110:
						*semaphores = 0b10;
						break;
					case 0b0111:
						*semaphores = 0b01;
						break;
					case 0b1000:
						*semaphores = 0b10;
						break;
					case 0b1001:
						*semaphores = 0b10;
						break;
					case 0b1010:
						*semaphores = 0b10;
						break;
					case 0b1011:
						*semaphores = 0b01;
						break;
					case 0b1100:
						*semaphores = 0b10;
						break;
					case 0b1101:
						*semaphores = 0b10;
						break;
					case 0b1110:
						*semaphores = 0b10;
						break;
					case 0b1111:
						*semaphores = 0b10;
						break;
					default:
						*semaphores = 0b11;
				}
}
