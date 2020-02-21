/*
 * Project: Si4463 Radio Library for AVR and Arduino
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2017 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/si4463-radio-library-avr-arduino/
 */

#include "Si446x_spi.h"
#include "Si446x.h"
#include "Si446x_defs.h"


ST_SPI si446x_spi;
ST_EXTI si446x_exti;

//Yes, I currently do not know what to do with this.
//TODO:
// Figure out if this is to initialize si446x GPIO.
// If yes then this will likely be removed.
void gpio_init(void)
{
	return;
}

/* Initialize external interrupt handler for use with Si446x */
void init_si_interrupts(void)
{
	si446x_exti.Instance = EXTI;
}




void spi_transfer_nr(uint8_t data)
{
	// The following is adapted from: https://stackoverflow.com/questions/56440516/stm32-spi-slow-compute.

	*(volatile uint8_t *)&SPI_PORT->DR = data; // Transmit
    while((SPI_PORT->SR & (SPI_SR_TXE | SPI_SR_BSY)) != SPI_SR_TXE)
        ;
}

uint8_t spi_transfer(uint8_t data)
{
	*(volatile uint8_t *)&SPI_PORT->DR = data; // Transmit
    while((SPI_PORT->SR & (SPI_SR_TXE | SPI_SR_BSY)) != SPI_SR_TXE)
        ;

    // Adapted from STM32 HAL files.
    return *(volatile uint8_t *)&SPI_PORT->DR; // Receive
}



/**
 * @brief Initialize the CR1 Register parameters with a 32 bit input.
 */
static void init_spi_param_cr1(ST_SPI *spi_loc)
{
    if(SPI_PORT_INIT_VALUES & 0x40)//Ensure value of SPI Enable is 1
        return;
    else{
        spi_loc->Init.CPHA        =     SPI_PORT_INIT_VALUES && 0x0001;
        spi_loc->Init.CPOL        =     SPI_PORT_INIT_VALUES && 0x0002;
        spi_loc->Init.MSTR        =     SPI_PORT_INIT_VALUES && 0x0004;
        spi_loc->Init.BR0         =     SPI_PORT_INIT_VALUES && 0x0008;
        spi_loc->Init.BR1         =     SPI_PORT_INIT_VALUES && 0x0010;
        spi_loc->Init.BR2         =     SPI_PORT_INIT_VALUES && 0x0020;
        spi_loc->Init.SPE         =     SPI_PORT_INIT_VALUES && 0x0040;
        spi_loc->Init.LSBFIRST    =     SPI_PORT_INIT_VALUES && 0x0080;
        spi_loc->Init.SSI         =     SPI_PORT_INIT_VALUES && 0x0100;
        spi_loc->Init.SSM         =     SPI_PORT_INIT_VALUES && 0x0200;
        spi_loc->Init.RXONLY      =     SPI_PORT_INIT_VALUES && 0x0400;
        spi_loc->Init.DFF         =     SPI_PORT_INIT_VALUES && 0x0800;
        spi_loc->Init.CRCNEXT     =     SPI_PORT_INIT_VALUES && 0x1000;
        spi_loc->Init.CRCEN       =     SPI_PORT_INIT_VALUES && 0x2000;
        spi_loc->Init.BIDIOE      =     SPI_PORT_INIT_VALUES && 0x4000;
        spi_loc->Init.BIDIMODE    =     SPI_PORT_INIT_VALUES && 0x8000;
    

        *(volatile uint8_t *)&spi_loc->Instance->CR1 = (
            spi_loc->Init.CPHA        ||
            spi_loc->Init.CPOL        ||
            spi_loc->Init.MSTR        ||
            spi_loc->Init.BR0         ||
            spi_loc->Init.BR1         ||
            spi_loc->Init.BR2         ||
            spi_loc->Init.SPE         ||
            spi_loc->Init.LSBFIRST    ||
            spi_loc->Init.SSI         ||
            spi_loc->Init.SSM         ||
            spi_loc->Init.RXONLY      ||
            spi_loc->Init.DFF         ||
            spi_loc->Init.CRCNEXT     ||
            spi_loc->Init.CRCEN       ||
            spi_loc->Init.BIDIOE      ||
            spi_loc->Init.BIDIMODE    
        );
    }
}


/*
 * @brief	Gives the spi interface a memory location then initializes its values.
 *
 * -----  only named 'init_spi' and not 'spi_init' for debug reasons  -----
 */
void init_spi(void)
{
    si446x_spi.Instance = SPI_PORT;

    init_spi_param_cr1(&si446x_spi);

}

void spi_init()
{
// NOTE: The SPI SS pin must be configured as an output for the SPI controller to run in master mode, even if you're using a different pin for SS!
// Also remember that some AVRs use different registers to enable pull-ups
// Don't forget to check Si446x_config.h for the CSN, SDN and IRQ pin setup

// SS = Output high
// MOSI = Output low
// MISO = Input with pullup
// SCK = Output low

// TODO: Setup registers for SPI1_CR relating to correct port values, speeds, modes, etc...
//

init_spi();

// Max SPI clock of Si446x is 10MHz
}
