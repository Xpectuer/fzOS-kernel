#include <version.h>
#include <kernel.h>
#include <printk.h>
#include <fbcon.h>
#include <memorysetup.h>
#include <cpuid.h>
#include <acpi_parser.h>
#include <halt.h>

//定义的标准输入/输出。
char_dev stdio;

void kernel_main(KernelInfo info) {
    graphics_init(info.gop);
    graphics_clear_screen(0x001e1e1e);
    fbcon_init(&stdio);
    printk("\n Hello World! I am fzOS.\n");
    printk(" Kernel version: %s\n",VERSION);
    int width=info.gop->Mode->Info->PixelsPerScanLine/8-1;
    for(int i=0;i<width-2;i++)
    {
        printk("+");
    }
    char buff[100];
    get_processor_vendor(buff);
    buff[12]=0;
    printk("\n CPU information: %s ",buff);
    get_processor_name(buff);
    printk("%s\n",buff);
    memory_init(info.mem_map_descriptor_size,info.mem_map_size,info.memory_map);
    printk(" Parsing ACPI table......\n");
    parse_acpi(info.rsdp_address);
    halt();
}