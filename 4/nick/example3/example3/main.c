#include <avr/io.h>

char x,y,z,k;

int main(void)
{

	DDRB=0xFF; // ������������ PORTB �� output
	DDRD=0x00; // ������������ PORTD �� input
	DDRA=0x00; // ������������ PORTA �� input

	while(1)
	{
		x = PIND & 0x0F;	// ��������� PD3-PD0

		y = PIND & 0xF0;	// ��������� PD7-PD4
		y = y >> 4;			// �������� ������ ���� ���� ��� ����

		z = PINA & 0x0F;	// ��������� PA3-PA0

		k = PINA & 0xF0;	// ��������� PA7-PA4
		k = k >> 4;			// �������� ������ ���� ���� ��� ����

		PORTB = (x+y+z+k);	// ����������� ����������� ��� ������ ���� PORTB

	}

	return 0;

}