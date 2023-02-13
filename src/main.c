/******************************************************************************
* File Name: main.c
*
* Description: This code example features a 5-segment CAPSENSE slider and two
*              CAPSENSE buttons. Button 0 turns the LED ON, Button 1 turns the
*              LED OFF, and the slider controls the brightness of the LED. The
*              code example also features interfacing with Tuner GUI using I2C
*              interface.
*
*              This code example uses FreeRTOS. For documentation and API
*              references of FreeRTOS, visit : https://www.freertos.org
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2019-2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#include "cybsp.h"
#include "capsense_task.h"
#include "led_task.h"
#include <zephyr/device.h>


/*******************************************************************************
 * Global constants
 ******************************************************************************/
/* Priorities of user tasks in this project. configMAX_PRIORITIES is defined in
 * the FreeRTOSConfig.h and higher priority numbers denote high priority tasks.
 */
#define TASK_CAPSENSE_PRIORITY   (6u)
#define TASK_LED_PRIORITY        (5u)

/* Stack sizes of user tasks in this project */
#define TASK_CAPSENSE_STACK_SIZE (256u)
#define TASK_LED_STACK_SIZE      (128u)


/*******************************************************************************
* Function Name: main()
********************************************************************************
* Summary:
*  System entrance point. This function sets up user tasks and then starts
*  the RTOS scheduler.
*
* Return:
*  int
*
*******************************************************************************/
void main(void)
{
    cy_rslt_t result;
    uint16_t sleep_ms = 5000;

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

    /* Wait a few seconds before main() exit, giving the it an
	 * opportunity to dump any output.
	 */
    k_msleep(sleep_ms);
}


/* Create the user tasks. See the respective task definition for more
    * details of these tasks.
    */
K_THREAD_DEFINE(task_capsense_id, TASK_CAPSENSE_STACK_SIZE, task_capsense,
            NULL, NULL, NULL, TASK_CAPSENSE_PRIORITY, 0, 0);
K_THREAD_DEFINE(task_led_id, TASK_LED_STACK_SIZE, task_led,
            NULL, NULL, NULL, TASK_LED_PRIORITY, 0, 0);


/* [] END OF FILE  */
