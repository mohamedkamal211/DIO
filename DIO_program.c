#include "STD_Types.h"
#include "BIT_MATHS.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"



u8 DIO_u8SetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value){

	u8 Local_u8ErrorState =0;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: PORTA = Copy_u8Value; break;
	case DIO_u8PORTB: PORTB = Copy_u8Value; break;
	case DIO_u8PORTC: PORTC = Copy_u8Value; break;
	case DIO_u8PORTD: PORTD = Copy_u8Value; break;
	default :Local_u8ErrorState=1;
	}

	return Local_u8ErrorState ;



}
u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value){
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin <= DIO_u8PIN7){
		if(Copy_u8Value == DIO_u8PIN_LOW){
			switch(Copy_u8Port){
			case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}
		else if(Copy_u8Value == DIO_u8PIN_HIGH){
			switch(Copy_u8Port){
			case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8Pin);break;
			default: Local_u8ErrorState = 1;break;
			}
		}
		else{
			Local_u8ErrorState=1;
		}
	}
	else{ Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_u8puValue){
	u8 Local_u8ErrorState=0;
	if((Copy_u8puValue != NULL) && (Copy_u8Pin<DIO_u8PIN7)){
		switch (Copy_u8Port) {
		case DIO_u8PORTA : *Copy_u8puValue = GET_BIT(PINA,Copy_u8Pin);break;
		case DIO_u8PORTB : *Copy_u8puValue = GET_BIT(PINB,Copy_u8Pin);break;
		case DIO_u8PORTC : *Copy_u8puValue = GET_BIT(PINC,Copy_u8Pin);break;
		case DIO_u8PORTD : *Copy_u8puValue = GET_BIT(PIND,Copy_u8Pin);break;
		default : Local_u8ErrorState=1;break;
		}
	}
	else{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;
}



