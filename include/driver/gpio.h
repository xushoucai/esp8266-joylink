// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _DRIVER_GPIO_NEW_H_
#define _DRIVER_GPIO_NEW_H_
#include "esp_common.h"
#include "esp_err.h"

//#include <esp_types.h>
//#include "soc/gpio_reg.h"
//#include "soc/gpio_struct.h"
//#include "soc/rtc_io_reg.h"
//#include "soc/io_mux_reg.h"
//#include "soc/gpio_sig_map.h"
//#include "rom/gpio.h"
//#include "esp_attr.h"
//#include "esp_intr_alloc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_SEL_0              (BIT(0))                         /*!< Pin 0 selected */
#define GPIO_SEL_1              (BIT(1))                         /*!< Pin 1 selected */
#define GPIO_SEL_2              (BIT(2))                         /*!< Pin 2 selected */
#define GPIO_SEL_3              (BIT(3))                         /*!< Pin 3 selected */
#define GPIO_SEL_4              (BIT(4))                         /*!< Pin 4 selected */
#define GPIO_SEL_5              (BIT(5))                         /*!< Pin 5 selected */
#define GPIO_SEL_6              (BIT(6))                         /*!< Pin 6 selected */
#define GPIO_SEL_7              (BIT(7))                         /*!< Pin 7 selected */
#define GPIO_SEL_8              (BIT(8))                         /*!< Pin 8 selected */
#define GPIO_SEL_9              (BIT(9))                         /*!< Pin 9 selected */
#define GPIO_SEL_10             (BIT(10))                        /*!< Pin 10 selected */
#define GPIO_SEL_11             (BIT(11))                        /*!< Pin 11 selected */
#define GPIO_SEL_12             (BIT(12))                        /*!< Pin 12 selected */
#define GPIO_SEL_13             (BIT(13))                        /*!< Pin 13 selected */
#define GPIO_SEL_14             (BIT(14))                        /*!< Pin 14 selected */
#define GPIO_SEL_15             (BIT(15))                        /*!< Pin 15 selected */
//#define GPIO_SEL_16             (BIT(16))                        /*!< Pin 16 selected */

#define GPIO_PIN_REG_0          PERIPHS_IO_MUX_GPIO0_U
#define GPIO_PIN_REG_1          PERIPHS_IO_MUX_U0TXD_U
#define GPIO_PIN_REG_2          PERIPHS_IO_MUX_GPIO2_U
#define GPIO_PIN_REG_3          PERIPHS_IO_MUX_U0RXD_U
#define GPIO_PIN_REG_4          PERIPHS_IO_MUX_GPIO4_U
#define GPIO_PIN_REG_5          PERIPHS_IO_MUX_GPIO5_U
#define GPIO_PIN_REG_6          PERIPHS_IO_MUX_SD_CLK_U
#define GPIO_PIN_REG_7          PERIPHS_IO_MUX_SD_DATA0_U
#define GPIO_PIN_REG_8          PERIPHS_IO_MUX_SD_DATA1_U
#define GPIO_PIN_REG_9          PERIPHS_IO_MUX_SD_DATA2_U
#define GPIO_PIN_REG_10         PERIPHS_IO_MUX_SD_DATA3_U
#define GPIO_PIN_REG_11         PERIPHS_IO_MUX_SD_CMD_U
#define GPIO_PIN_REG_12         PERIPHS_IO_MUX_MTDI_U
#define GPIO_PIN_REG_13         PERIPHS_IO_MUX_MTCK_U
#define GPIO_PIN_REG_14         PERIPHS_IO_MUX_MTMS_U
#define GPIO_PIN_REG_15         PERIPHS_IO_MUX_MTDO_U
#define GPIO_PIN_REG_16         PERIPHS_IO_MUX_GPIO16_U

//#define GPIO_APP_CPU_INTR_ENA      (BIT(0))
//#define GPIO_APP_CPU_NMI_INTR_ENA  (BIT(1))
//#define GPIO_PRO_CPU_INTR_ENA      (BIT(2))
//#define GPIO_PRO_CPU_NMI_INTR_ENA  (BIT(3))
//#define GPIO_SDIO_EXT_INTR_ENA     (BIT(4))

#define GPIO_PIN_CONFIG                        0x00000003
#define GPIO_PIN_CONFIG_S                      11
#define GPIO_PIN_WAKEUP_ENABLE                 BIT10
#define GPIO_PIN_WAKEUP_ENABLE_S               10
#define GPIO_PIN_INT_TYPE                      0x00000007
#define GPIO_PIN_INT_TYPE_S                    7
#define GPIO_PIN_DRIVER                        BIT2
#define GPIO_PIN_DRIVER_S                      2
#define GPIO_PIN_SOURCE                        BIT0
#define GPIO_PIN_SOURCE_S                      0
#define GPIO_REG_ADDR(i)        (PERIPHS_GPIO_BASEADDR + GPIO_PIN0_ADDRESS + i*4)

#define GPIO_OUT_REG                    (PERIPHS_GPIO_BASEADDR + 0x00)
#define GPIO_OUT_W1TS_REG               (PERIPHS_GPIO_BASEADDR + 0x04)
#define GPIO_OUT_W1TC_REG               (PERIPHS_GPIO_BASEADDR + 0x08)
#define GPIO_ENABLE_REG                 (PERIPHS_GPIO_BASEADDR + 0x0c)
#define GPIO_ENABLE_W1TS_REG            (PERIPHS_GPIO_BASEADDR + 0x10)
#define GPIO_ENABLE_W1TC_REG            (PERIPHS_GPIO_BASEADDR + 0x14)
#define GPIO_IN_REG                     (PERIPHS_GPIO_BASEADDR + 0x18)
#define GPIO_STATUS_REG                 (PERIPHS_GPIO_BASEADDR + 0x1c)
#define GPIO_STATUS_W1TS_REG            (PERIPHS_GPIO_BASEADDR + 0x20)
#define GPIO_STATUS_W1TC_REG            (PERIPHS_GPIO_BASEADDR + 0x24)

#define GPIO_MODE_DEF_INPUT           (BIT0)
#define GPIO_MODE_DEF_OUTPUT          (BIT1)
#define GPIO_MODE_DEF_OD              (BIT2)

//#define GPIO_PIN_COUNT              (16)
extern const uint32_t GPIO_PIN_MUX_REG[GPIO_PIN_COUNT];

#define GPIO_IS_VALID_GPIO(gpio_num)      ((gpio_num < GPIO_PIN_COUNT && GPIO_PIN_MUX_REG[gpio_num] != 0))   //to decide whether it is a valid GPIO number
#define GPIO_IS_VALID_OUTPUT_GPIO(gpio_num)      ((GPIO_IS_VALID_GPIO(gpio_num)) && (gpio_num < 16))         //to decide whether it can be a valid GPIO number of output mode

typedef enum {
    GPIO_NUM_0 = 0,     /*!< GPIO0, input and output */
    GPIO_NUM_1 = 1,     /*!< GPIO1, input and output */
    GPIO_NUM_2 = 2,     /*!< GPIO2, input and output */
    GPIO_NUM_3 = 3,     /*!< GPIO3, input and output */
    GPIO_NUM_4 = 4,     /*!< GPIO4, input and output */
    GPIO_NUM_5 = 5,     /*!< GPIO5, input and output */
    GPIO_NUM_6 = 6,     /*!< GPIO6, input and output */
    GPIO_NUM_7 = 7,     /*!< GPIO7, input and output */
    GPIO_NUM_8 = 8,     /*!< GPIO8, input and output */
    GPIO_NUM_9 = 9,     /*!< GPIO9, input and output */
    GPIO_NUM_10 = 10,   /*!< GPIO10, input and output */
    GPIO_NUM_11 = 11,   /*!< GPIO11, input and output */
    GPIO_NUM_12 = 12,   /*!< GPIO12, input and output */
    GPIO_NUM_13 = 13,   /*!< GPIO13, input and output */
    GPIO_NUM_14 = 14,   /*!< GPIO14, input and output */
    GPIO_NUM_15 = 15,   /*!< GPIO15, input and output */
//  GPIO_NUM_16 = 16,   /*!< GPIO16, input and output */
    GPIO_NUM_MAX = 16,
} gpio_num_t;

typedef enum {
    GPIO_INTR_DISABLE = 0,     /*!< Disable GPIO interrupt                             */
    GPIO_INTR_POSEDGE = 1,     /*!< GPIO interrupt type : rising edge                  */
    GPIO_INTR_NEGEDGE = 2,     /*!< GPIO interrupt type : falling edge                 */
    GPIO_INTR_ANYEDGE = 3,     /*!< GPIO interrupt type : both rising and falling edge */
    GPIO_INTR_LOW_LEVEL = 4,   /*!< GPIO interrupt type : input low level trigger      */
    GPIO_INTR_HIGH_LEVEL = 5,  /*!< GPIO interrupt type : input high level trigger     */
    GPIO_INTR_MAX,
} gpio_int_type_t;

typedef enum {
    GPIO_MODE_INPUT = GPIO_MODE_DEF_INPUT,                                                         /*!< GPIO mode : input only                           */
    GPIO_MODE_OUTPUT = GPIO_MODE_DEF_OUTPUT,                                                       /*!< GPIO mode : output only mode                     */
    GPIO_MODE_OUTPUT_OD = ((GPIO_MODE_DEF_OUTPUT) | (GPIO_MODE_DEF_OD)),                           /*!< GPIO mode : output only with open-drain mode     */
    GPIO_MODE_INPUT_OUTPUT_OD = ((GPIO_MODE_DEF_INPUT) | (GPIO_MODE_DEF_OUTPUT) | (GPIO_MODE_DEF_OD)), /*!< GPIO mode : output and input with open-drain mode*/
    GPIO_MODE_INPUT_OUTPUT = ((GPIO_MODE_DEF_INPUT) | (GPIO_MODE_DEF_OUTPUT)),                     /*!< GPIO mode : output and input mode                */
} gpio_mode_t;

typedef enum {
    GPIO_PULLUP_DISABLE = 0x0,     /*!< Disable GPIO pull-up resistor */
    GPIO_PULLUP_ENABLE = 0x1,      /*!< Enable GPIO pull-up resistor */
} gpio_pullup_t;

//typedef enum {
//    GPIO_PULLDOWN_DISABLE = 0x0,   /*!< Disable GPIO pull-down resistor */
//    GPIO_PULLDOWN_ENABLE = 0x1,    /*!< Enable GPIO pull-down resistor  */
//} gpio_pulldown_t;

/**
 * @brief Configuration parameters of GPIO pad for gpio_config function
 */
typedef struct {
    uint64_t pin_bit_mask;          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    gpio_mode_t mode;               /*!< GPIO mode: set input/output mode                     */
    gpio_pullup_t pull_up_en;       /*!< GPIO pull-up                                         */
//    gpio_pulldown_t pull_down_en;   /*!< GPIO pull-down                                       */
    gpio_int_type_t intr_type;      /*!< GPIO interrupt type                                  */
} gpio_config_t;

typedef enum {
    GPIO_PULLUP_ONLY,               /*!< Pad pull up            */
//    GPIO_PULLDOWN_ONLY,             /*!< Pad pull down          */
//    GPIO_PULLUP_PULLDOWN,           /*!< Pad pull up + pull down*/
    GPIO_FLOATING,                  /*!< Pad floating           */
} gpio_pull_mode_t;

typedef void (*gpio_isr_t)(void*);
//typedef intr_handle_t gpio_isr_handle_t;

/**
 * @brief GPIO common configuration
 *
 *        Configure GPIO's Mode,pull-up,PullDown,IntrType
 *
 * @param  pGPIOConfig Pointer to GPIO configure struct
 *
 * @return
 *     - ESP_OK success
 *     - ESP_ERR_INVALID_ARG Parameter error
 *
 */
esp_err_t gpio_config(const gpio_config_t* pGPIOConfig);

/**
 * @brief  GPIO set interrupt trigger type
 *
 * @param  gpio_num GPIO number. If you want to set the trigger type of e.g. of GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @param  intr_type Interrupt type, select from gpio_int_type_t
 *
 * @return
 *     - ESP_OK  Success
 *     - ESP_ERR_INVALID_ARG Parameter error
 *
 */
esp_err_t gpio_set_intr_type(gpio_num_t gpio_num, gpio_int_type_t intr_type);

/**
 * @brief  Enable GPIO module interrupt signal
 *
 * @param  gpio_num GPIO number. If you want to enable an interrupt on e.g. GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG Parameter error
 *
 */
esp_err_t gpio_intr_enable();

/**
 * @brief  Disable GPIO module interrupt signal
 *
 * @param  gpio_num GPIO number. If you want to disable the interrupt of e.g. GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return
 *     - ESP_OK success
 *     - ESP_ERR_INVALID_ARG Parameter error
 *
 */
esp_err_t gpio_intr_disable();

/**
 * @brief  GPIO set output level
 *
 * @param  gpio_num GPIO number. If you want to set the output level of e.g. GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @param  level Output level. 0: low ; 1: high
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG GPIO number error
 *
 */
esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level);

/**
 * @brief  GPIO get input level
 *
 * @param  gpio_num GPIO number. If you want to get the logic level of e.g. pin GPIO16, gpio_num should be GPIO_NUM_16 (16);
 *
 * @return
 *     - 0 the GPIO input level is 0
 *     - 1 the GPIO input level is 1
 *
 */
int gpio_get_level(gpio_num_t gpio_num);

/**
 * @brief	 GPIO set direction
 *
 * Configure GPIO direction,such as output_only,input_only,output_and_input
 *
 * @param  gpio_num  Configure GPIO pins number, it should be GPIO number. If you want to set direction of e.g. GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @param  mode GPIO direction
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG GPIO error
 *
 */
esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode);

/**
 * @brief  Configure GPIO pull-up/pull-down resistors
 *
 * Only pins that support both input & output have integrated pull-up and pull-down resistors. Input-only GPIOs 34-39 do not.
 *
 * @param  gpio_num GPIO number. If you want to set pull up or down mode for e.g. GPIO16, gpio_num should be GPIO_NUM_16 (16);
 * @param  pull GPIO pull up/down mode.
 *
 * @return
 *     - ESP_OK Success
 *     - ESP_ERR_INVALID_ARG : Parameter error
 *
 */
esp_err_t gpio_set_pull_mode(gpio_num_t gpio_num, gpio_pull_mode_t pull);

/**
  * @brief Enable GPIO wake-up function.
  *
  * @param gpio_num GPIO number.
  *
  * @param intr_type GPIO wake-up type. Only GPIO_INTR_LOW_LEVEL or GPIO_INTR_HIGH_LEVEL can be used.
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_wakeup_enable(gpio_num_t gpio_num, gpio_int_type_t intr_type);

/**
  * @brief Disable GPIO wake-up function.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_wakeup_disable(gpio_num_t gpio_num);

/**
 * @brief   Register GPIO interrupt handler, the handler is an ISR.
 *          The handler will be attached to the same CPU core that this function is running on.
 *
 * This ISR function is called whenever any GPIO interrupt occurs. See
 * the alternative gpio_install_isr_service() and
 * gpio_isr_handler_add() API in order to have the driver support
 * per-GPIO ISRs.
 *
 * @param  fn  Interrupt handler function.
 * @param  intr_alloc_flags Flags used to allocate the interrupt. One or multiple (ORred)
 *            ESP_INTR_FLAG_* values. See esp_intr_alloc.h for more info.
 * @param  arg  Parameter for handler function
 * @param  handle Pointer to return handle. If non-NULL, a handle for the interrupt will be returned here.
 *
 * \verbatim embed:rst:leading-asterisk
 * To disable or remove the ISR, pass the returned handle to the :doc:`interrupt allocation functions </api-reference/system/intr_alloc>`.
 * \endverbatim
 *
 * @return
 *     - ESP_OK Success ;
 *     - ESP_ERR_INVALID_ARG GPIO error
 */
//esp_err_t gpio_isr_register(void (*fn)(void*), void * arg, int intr_alloc_flags, gpio_isr_handle_t *handle);

/**
  * @brief Enable pull-up on GPIO.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_pullup_en(gpio_num_t gpio_num);

/**
  * @brief Disable pull-up on GPIO.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_pullup_dis(gpio_num_t gpio_num);

/**
  * @brief Enable pull-down on GPIO.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_pulldown_en(gpio_num_t gpio_num);

/**
  * @brief Disable pull-down on GPIO.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_pulldown_dis(gpio_num_t gpio_num);

/**
  * @brief Install the driver's GPIO ISR handler service, which allows per-pin GPIO interrupt handlers.
  *
  * This function is incompatible with gpio_isr_register() - if that function is used, a single global ISR is registered for all GPIO interrupts. If this function is used, the ISR service provides a global GPIO ISR and individual pin handlers are registered via the gpio_isr_handler_add() function.
  *
  * @param intr_alloc_flags Flags used to allocate the interrupt. One or multiple (ORred)
  *            ESP_INTR_FLAG_* values. See esp_intr_alloc.h for more info.
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_FAIL Operation fail
  *     - ESP_ERR_NO_MEM No memory to install this service
  */
esp_err_t gpio_install_isr_service();

/**
  * @brief Uninstall the driver's GPIO ISR service, freeing related resources.
  */
void gpio_uninstall_isr_service();

/**
  * @brief Add ISR handler for the corresponding GPIO pin.
  *
  * Call this function after using gpio_install_isr_service() to
  * install the driver's GPIO ISR handler service.
  *
  * The pin ISR handlers no longer need to be declared with IRAM_ATTR,
  * unless you pass the ESP_INTR_FLAG_IRAM flag when allocating the
  * ISR in gpio_install_isr_service().
  *
  * This ISR handler will be called from an ISR. So there is a stack
  * size limit (configurable as "ISR stack size" in menuconfig). This
  * limit is smaller compared to a global GPIO interrupt handler due
  * to the additional level of indirection.
  *
  * @param gpio_num GPIO number
  * @param isr_handler ISR handler function for the corresponding GPIO number.
  * @param args parameter for ISR handler.
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_STATE Wrong state, the ISR service has not been initialized.
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void* args);

/**
  * @brief Remove ISR handler for the corresponding GPIO pin.
  *
  * @param gpio_num GPIO number
  *
  * @return
  *     - ESP_OK Success
  *     - ESP_ERR_INVALID_STATE Wrong state, the ISR service has not been initialized.
  *     - ESP_ERR_INVALID_ARG Parameter error
  */
esp_err_t gpio_isr_handler_remove(gpio_num_t gpio_num);

#ifdef __cplusplus
}
#endif

#endif /* _DRIVER_GPIO_H_ */
