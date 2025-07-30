CROSS = arm-none-eabi
CFLAGS = -nostdlib -mcpu=arm926ej-s -O2

all: kernel.bin

kernel.elf: startup.s main.c linker.ld
	$(CROSS)-gcc $(CFLAGS) -T linker.ld startup.s main.c -o $@

kernel.bin: kernel.elf
	$(CROSS)-objcopy -O binary $< $@

clean:
	rm -f *.o *.elf *.bin
