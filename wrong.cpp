#include <errno.h>

#define SECTORSIZE 4096
int _sector_offset = 8L * 1024 * 1024 - (256L * 1024) + (63 * SECTORSIZE);

/*
   No.  CPU  DRAM PCI  Option
====================================
    0   300  300  100  Default
    1   200  200  33
    z   400  300  100  Not visible
    x   444  333  100  Not visible
    c   500  250  100  Not visible
*/

int clock_no = 0;  // defaults to 0
int clock_freq[5] = {300, 200, 400, 444, 500};
char clock_array[5][6] = {
    {0x48, 0x03, 0x23, 0x02, 0x7F, 0x07},
    {0x30, 0x03, 0x0F, 0x02, 0x8F, 0x07},
    {0x90, 0x53, 0x23, 0x02, 0x9F, 0x07},
    {0xA0, 0x53, 0x23, 0x1A, 0x4F, 0x08},
    {0x50, 0x42, 0x23, 0x1A, 0xBF, 0x07}
};


// Modify SPI Flash to Set CPU Clock
void write_spi_byte(unsigned short iobase, unsigned char n)
{
    io_outpb(iobase, n);
    while ((io_inpb(iobase + 3) & 0x10) == 0);
}

unsigned char read_spi_byte(unsigned short iobase)
{
    io_outpb(iobase + 1, 0); //triggle SPI read
    while ((io_inpb(iobase + 3) & 0x20) == 0);
    return io_inpb(iobase + 1); // read SPI data
}

void enable_cs(unsigned short iobase)
{
    io_outpb(iobase + 4, 0);
}

void disable_cs(unsigned short iobase)
{
    io_outpb(iobase + 4, 1);
}

void write_spi_24bit_addr(unsigned short iobase, unsigned long addr)
{
    write_spi_byte(iobase, (unsigned char)((addr >> 16) & 0xff));
    write_spi_byte(iobase, (unsigned char)((addr >> 8) & 0xff));
    write_spi_byte(iobase, (unsigned char)((addr) & 0xff));
}
