#include <time.h>
void confirmationscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void confirmationscreen_entry(int* buffer);
void confirmationscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void confirmationscreen_exit (int* buffer);
