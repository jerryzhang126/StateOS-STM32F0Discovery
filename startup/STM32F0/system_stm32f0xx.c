/******************************************************************************
 * @file    system_stm32f0xx.c
 * @author  Rajmund Szymanski
 * @date    03.03.2016
 * @brief   This file provides set of configuration functions for STM32F0 uC.
 ******************************************************************************/

#include <stm32f0xx.h>

/* -------------------------------------------------------------------------- */

//#define PLL_SOURCE_HSI        // PLL source: HSI ( 8MHz)
  #define PLL_SOURCE_HSE        // PLL source: HSE ( 8MHz)
//#define PLL_SOURCE_HSE_BYPASS // PLL source: HSE ( 8MHz)

/* -------------------------------------------------------------------------- */

#define MHz    1000000
#define HSI_FREQ     8 /* MHz */
#define HSE_FREQ     8 /* MHz */
#define USB_FREQ    48 /* MHz */
#define CPU_FREQ    48 /* MHz */
#define VDD       3000 /* mV  */

#define LATENCY  ((100*CPU_FREQ+VDD/2)/VDD)

#ifdef  PLL_SOURCE_HSI
#define PLLSRC (HSI_FREQ)
#else
#define PLLSRC (HSE_FREQ)
#endif
#define PLLMUL (CPU_FREQ/(PLLSRC/2))

/* -------------------------------------------------------------------------- */

#ifndef __NO_SYSTEM_INIT
__WEAK
void SystemInit( void )
{
	FLASH->ACR = LATENCY | FLASH_ACR_PRFTBE;
#ifdef  PLL_SOURCE_HSI
	RCC->CFGR = RCC_CFGR_PLLSRC_HSI_DIV2 | ((PLLMUL-2)<<18);
#else
#ifdef  PLL_SOURCE_HSE_BYPASS
	RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
#else
	RCC->CR |= RCC_CR_HSEON;
#endif//PLL_SOURCE_HSE_BYPASS
	while ((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY);

	RCC->CFGR = RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV2 | ((PLLMUL-2)<<18);
#endif//PLL_SOURCE_HSI
	RCC->CR |= RCC_CR_PLLON;
	while ((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY);

	RCC->CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE_DIV1 | RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}
#endif//__NO_SYSTEM_INIT

/* -------------------------------------------------------------------------- */

#ifndef __NO_SYSTEM_INIT
__WEAK
uint32_t SystemCoreClock = CPU_FREQ * MHz;
#else
__WEAK
uint32_t SystemCoreClock = HSI_FREQ * MHz;
#endif//__NO_SYSTEM_INIT

/* -------------------------------------------------------------------------- */
