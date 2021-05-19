#include <avr/io.h>

char x, dummy;

int main(void) {

	DDRA = 0b11111111; // ������������ ��� PORTA �� output
	DDRC = 0b00000000; // ������������ ��� PORTC �� input

	x = 0b00000001;	// ������������ ���������� ��� ������ �������� LED

	PORTA = x;

	while(1) {
		if ((PINC & 0b0001) == 0b0001) { // ������� ��������� push-button SW0

			while ((PINC & 0b0001) == 0b0001); // ������� ���������� push-button SW0

			// SW0: ��������-���������� ��� led ��� ���� �������� (�������)
			
			if (x == 0b10000000)
			x = 0b00000001;
			else
			x = x << 1;
		}

		if ((PINC & 0b0010) == 0b0010) { // ������� ��������� push-button SW1

			while ((PINC & 0b0010) == 0b0010); // ������� ���������� push-button SW1

			// SW1: ��������-���������� ��� led ��� ���� ����� (�������)
			
			if (x == 0b00000001)
			x = 0b10000000;
			else
			x = x >> 1;
		}

		if ((PINC & 0b0100) == 0b0100) { // ������� ��������� push-button SW2

			while ((PINC & 0b0100) == 0b0100); // ������� ���������� push-button SW2

			// SW2: ���������� ��� ��������� led ���� ���� MSB (led7)
			
			x = 0b10000000;
		}

		if ((PINC & 0b1000) == 0b1000) { // ������� ��������� push-button SW3

			while ((PINC & 0b1000) == 0b1000); // ������� ���������� push-button SW3
			
			// SW3: ���������� ��� ��������� led ���� ������ ��� ���� LSB (led0)
			
			x = 0b00000001;
		}

		PORTA = x; // ������ �� PORTA
		dummy = 0;
	}

	return 0;
}