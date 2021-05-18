#include <avr/io.h>

char x;

int main(void)
{
	DDRB=0xFF;							// ������������ PORTB �� output
	DDRA=0x00;							// ������������ PORTA �� input

	x = 1;								// ������������ ���������� ��� ������ �������� LED

	while(1)
	{
		if ((PINA & 0x01) == 0x01) {	// ������� ��������� push-button SW0

			while ((PINA & 0x01) == 1); // ������� ���������� push-button SW0

			if (x==128)					// ������� ������������
			x = 1;
			else
			x = x << 1;					// �������� ��������
		}

		PORTB = x;						// ������ �� PORTB
	}

	return 0;
}