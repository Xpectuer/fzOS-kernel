#include <graphics.h>
#include <types.h>

void kernel_draw_char_pos(U32 color);
void kernel_print_U64_hex(U64 data, U32 color);
void kernel_print_U8_hex(U8 data, U32 color);
void kernel_log_print_char(char c,U32 color);
void kernel_log_print_string(char* str,U32 color);
void kernel_log_line_break();
