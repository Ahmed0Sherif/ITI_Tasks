
#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#define INTERN_PULL_UP	1
#define NO_PULL_UP		0


void HSW_voidSwitchInit(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8PullUp);

u8 HSW_u8SwitchGetValue (u8 copy_u8Port, u8 copy_u8Pin);

#endif