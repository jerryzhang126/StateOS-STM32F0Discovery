/******************************************************************************

    @file    StateOS: osconfig.h
    @author  Rajmund Szymanski
    @date    14.12.2017
    @brief   StateOS config file for STM32F0 uC.

 ******************************************************************************

    StateOS - Copyright (C) 2013 Rajmund Szymanski.

    This file is part of StateOS distribution.

    StateOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    StateOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#pragma once

// ----------------------------
// cpu frequency in Hz
// default value: none
#define CPU_FREQUENCY  48000000

// ----------------------------
// os frequency in Hz
// OS_TICKLESS == 0 => dafault value:    1000
// OS_TICKLESS != 0 => dafault value: 1000000 (tick-less mode)
#define  OS_FREQUENCY      1000

// ----------------------------
// using tick-less mode
// default value: 0
#define  OS_TICKLESS          0

// ----------------------------
// system mode, round-robin frequency in Hz
// OS_ROBIN == 0 => os works in cooperative mode
// OS_ROBIN >  0 => os works in preemptive mode, OS_ROBIN indicates round-robin frequency
// default value: 0
#define  OS_ROBIN          1000

// ----------------------------
// critical sections protection level
// OS_LOCK_LEVEL == 0 or  __CORTEX_M <  3 => entrance to a critical section blocks all interrupts
// OS_LOCK_LEVEL >  0 and __CORTEX_M >= 3 => entrance to a critical section blocks interrupts with urgency lower or equal (the priority value greater or equal) than OS_LOCK_LEVEL
// default value: 0
#define  OS_LOCK_LEVEL        0

// ----------------------------
// priority of main process
// default value: 0 (the same as priority of idle process)
#define  OS_MAIN_PRIO         0

// ----------------------------
// os heap size in bytes
// OS_HEAP_SIZE == 0 => functions 'xxx_create' use 'malloc' provided with the compiler libraries
// OS_HEAP_SIZE >  0 => functions 'xxx_create' allocate memory on a dedicated system heap, OS_HEAP_SIZE indicates size of the heap
// default value: 0
#define  OS_HEAP_SIZE         0

// ----------------------------
// default task stack size in bytes
// default value: 256
#define  OS_STACK_SIZE      256

// ----------------------------
// idle task stack size in bytes
// default value: 128
#define  OS_IDLE_STACK      128
