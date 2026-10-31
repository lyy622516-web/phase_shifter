#ifndef __CS32F0XX_CONF_H__
#define __CS32F0XX_CONF_H__


/**
  * @file    RCU/RCU_HXT/cs32f0xx_conf.h 
  * @brief   Library configuration file.
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2018.11.01         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note 
  * <h2><center>&copy; COPYRIGHT 2018 ChipSea</center></h2>
  *
  * Licensed under MCD-CS Liberty SW License Agreement V1, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.chipsea.com/software_license_agreement_liberty_v1
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  */


#include "cs32f0xx_adc.h"
#include "cs32f0xx_crc.h"
#include "cs32f0xx_debug.h"
#include "cs32f0xx_dma.h"
#include "cs32f0xx_exti.h"
#include "cs32f0xx_flash.h"
#include "cs32f0xx_gpio.h"
#include "cs32f0xx_syscfg.h"
#include "cs32f0xx_i2c.h"
#include "cs32f0xx_fwdt.h"
#include "cs32f0xx_pmu.h"
#include "cs32f0xx_rcu.h"
#include "cs32f0xx_rtc.h"
#include "cs32f0xx_spi.h"
#include "cs32f0xx_tim.h"
#include "cs32f0xx_usart.h"
#include "cs32f0xx_wwdt.h"
#include "cs32f0xx_misc.h"  



/* #define USE_FULL_ASSERT    1 */

#ifdef  USE_FULL_ASSERT

/**
  * @brief  The ASSERT macro is used for function's parameters check.
  */
  #define ASSERT(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))

  /**
  * @fn void assert_failed(uint8_t* fileName, uint32_t line)
  * @brief  Reports the name of the file and the  line number error.
  * @param  fileName: pointer to the  file name
  * @param  line:  error line  number
  * @return None
  */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define ASSERT(expr) ((void)0)
#endif 

#endif 

