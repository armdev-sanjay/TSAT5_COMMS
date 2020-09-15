/*
 * Project: Si4463 Radio Library for AVR and Arduino
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2017 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/si4463-radio-library-avr-arduino/
 */

#include "stm32l0xx_hal.h"
#include "Si446x_spi.h"
#include "Si446x_config.h"

// NOTE: The SPI SS pin must be configured as an output for the SPI controller to run in master mode, even if you're using a different pin for SS!
// Also remember that some AVRs use different registers to enable pull-ups
// Don't forget to check Si446x_config.h for the CSN, SDN and IRQ pin setup

// SS = Output high
// MOSI = Output low
// MISO = Input with pullup
// SCK = Output low
// Max SPI clock of Si446x is 10MHz

// TODO: Setup registers for SPI1_CR relating to correct port values, speeds, modes, etc...


void spi_init()
{
	SPI_PORT->CR1 |= SPI_CR1_SPE; // Enable SPI.
}
