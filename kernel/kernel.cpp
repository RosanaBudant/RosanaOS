extern "C" void kernel_main()
{
    volatile unsigned short* vga =
        (volatile unsigned short*)0xB8000;

    const char* msg = "RosanaOS v0.1";

    for (int i = 0; msg[i] != '\0'; i++)
    {
        vga[i] = (0x07 << 8) | msg[i];
    }

    while (true) {}
}
