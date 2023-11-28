#pragma once
#ifndef MOUSE_H
#define MOUSE_H
#define ZwClose(handle) NtClose(handle)

typedef int BOOL;

BOOL mouse_open(void);
void mouse_close(void);
void mouse_move(char button, char x, char y, char wheel);

#endif