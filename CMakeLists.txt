# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(capsense)

set(PDL_DRIVER_DIR ${ZEPHYR_HAL_INFINEON_MODULE_DIR}/mtb-pdl-cat1/drivers/source)
set(HAL_SOURCE_DIR ${ZEPHYR_HAL_INFINEON_MODULE_DIR}/mtb-hal-cat1/COMPONENT_PSOC6HAL/source)
set(CAPSENSE_LIB_DIR "${ZEPHYR_HAL_INFINEON_MODULE_DIR}/../../lib/capsense")

zephyr_library_sources(${PDL_DRIVER_DIR}/cy_tcpwm_pwm.c ${PDL_DRIVER_DIR}/cy_scb_ezi2c.c ${PDL_DRIVER_DIR}/cy_scb_i2c.c)
zephyr_library_sources(${HAL_SOURCE_DIR}/cyhal_pwm.c ${HAL_SOURCE_DIR}/cyhal_tcpwm_common.c ${HAL_SOURCE_DIR}/cyhal_ezi2c.c)
zephyr_include_directories(${CAPSENSE_LIB_DIR})
FILE(GLOB capsense_sources ${CAPSENSE_LIB_DIR}/*.c)
zephyr_library_sources(${capsense_sources} ${PDL_DRIVER_DIR}/cy_csd.c)

zephyr_include_directories(GeneratedSource src)
FILE(GLOB app_sources GeneratedSource/*c src/*.c)
target_sources(app PRIVATE ${app_sources})

add_library(libcy_capsense STATIC IMPORTED GLOBAL)
set_target_properties(libcy_capsense PROPERTIES IMPORTED_LOCATION ${CAPSENSE_LIB_DIR}/COMPONENT_SOFTFP/TOOLCHAIN_GCC_ARM/libcy_capsense.a)
target_link_libraries(app PUBLIC libcy_capsense)
