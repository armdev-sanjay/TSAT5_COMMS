/*
 * Project: Si4463 Radio Library for AVR and Arduino
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2017 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/si4463-radio-library-avr-arduino/
 */

#ifndef SI446X_SPI_H_
#define SI446X_SPI_H_

#include "main.h"
#include "Si446x_defs.h"


// TODO: Move the IRQ stuff to a separate file?


typedef struct{
	uint32_t		CRv;		//Control Register values
	uint32_t		IMRv;		//Interrupt Mask Register values
	uint32_t		RSTRv;		//Rising-Edge Trigger Enable Register
	uint32_t		FSTRv;		//Falling-Edge Trigger Enable Register
}ST_EXTIINIT;

typedef struct{
	EXTI_TypeDef	*Instance;	//Instance of EXTI to work with
	ST_EXTIINIT		Init;		//Initialization parameters
}ST_EXTI;





typedef struct{
    uint32_t        CPHA;       //Clock Phase
    uint32_t        CPOL;       //Clock Polarity
    uint32_t        MSTR;       //Master Select
    uint32_t        BR0;        //Baud-Rate Prescaler bit 0
    uint32_t        BR1;        //Baud-Rate Prescaler bit 1
    uint32_t        BR2;        //Baud-Rate Prescaler bit 2
    uint32_t        SPE;        //SPI Peripheral Enable
    uint32_t        LSBFIRST;   //Least Significant Bit First Enable
    uint32_t        SSI;        //Software Slave Select Internal Default Bitvalue
    uint32_t        SSM;        //Software Slave Management
    uint32_t        RXONLY;     //RX Only Enable
    uint32_t        DFF;        //Data Frame Format
    uint32_t        CRCNEXT;    //CRC Transfer Next
    uint32_t        CRCEN;      //CRC Enable
    uint32_t        BIDIOE;     //Bidirectional Output Mode Enable
    uint32_t        BIDIMODE;   //Bidirectional Data Mode Enable
}ST_SPIINIT;


typedef struct{
    SPI_TypeDef     *Instance;  //Memory location of desired SPI
    ST_SPIINIT      Init;       //Init Params
}ST_SPI;



void gpio_init(void);

void spi_init(void);

void spi_transfer_nr(uint8_t data);

uint8_t spi_transfer(uint8_t data);




/**
 * @brief Initialize the SPI bus
 */
void init_spi();









#endif /* SI446X_SPI_H_ */
