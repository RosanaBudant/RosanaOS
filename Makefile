# ========================================
# Makefile para RosanaOS
# ========================================

# Compiladores
NASM = nasm
GPP = g++
LD = ld

# Flags do NASM
NASM_FLAGS = -f elf32

# Flags do G++ (para kernel C++)
GPP_FLAGS = -m32 -ffreestanding -nostdlib -fno-pie -fno-rtti -fno-exceptions -Wall -Wextra -std=c++11

# Flags do Linker
LD_FLAGS = -m elf_i386 -T linker.ld

# Diretórios
BUILD_DIR = build
ISO_DIR = iso

# Arquivos fonte
MULTIBOOT_SRC = boot/multiboot.asm
BOOT_SRC = boot/boot.asm
KERNEL_SRC = kernel/kernel.cpp

# Arquivos objeto
MULTIBOOT_OBJ = $(BUILD_DIR)/multiboot.o
BOOT_OBJ = $(BUILD_DIR)/boot.o
KERNEL_OBJ = $(BUILD_DIR)/kernel.o
OBJS = $(MULTIBOOT_OBJ) $(BOOT_OBJ) $(KERNEL_OBJ)

# Alvo final
KERNEL_ELF = $(BUILD_DIR)/kernel.elf
ISO = $(BUILD_DIR)/RosanaOS.iso

# ========================================
# Regras principais
# ========================================

all: $(ISO)

# Linkar o kernel
$(KERNEL_ELF): $(OBJS)
	@echo "🔗 Linkando kernel..."
	$(LD) $(LD_FLAGS) -o $@ $^
	@echo "✅ Kernel criado: $@"
	@grub-file --is-x86-multiboot $@ && echo "✅ Multiboot OK" || echo "❌ ERRO: Não é Multiboot!"

# Compilar multiboot.asm
$(MULTIBOOT_OBJ): $(MULTIBOOT_SRC)
	@echo "🔧 Compilando multiboot.asm..."
	$(NASM) $(NASM_FLAGS) -o $@ $<

# Compilar boot.asm
$(BOOT_OBJ): $(BOOT_SRC)
	@echo "🔧 Compilando boot.asm..."
	$(NASM) $(NASM_FLAGS) -o $@ $<

# Compilar kernel.cpp
$(KERNEL_OBJ): $(KERNEL_SRC)
	@echo "🔧 Compilando kernel.cpp..."
	$(GPP) $(GPP_FLAGS) -c -o $@ $<

# Criar ISO
$(ISO): $(KERNEL_ELF)
	@echo "📀 Criando ISO..."
	cp $(KERNEL_ELF) $(ISO_DIR)/boot/kernel.elf
	grub-mkrescue -o $@ $(ISO_DIR)
	@echo "✅ ISO criado: $@"

# Limpar arquivos
clean:
	@echo "🧹 Limpando..."
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.iso
	@echo "✅ Limpo!"

# Executar no QEMU
run: $(ISO)
	@echo "🚀 Executando no QEMU..."
	qemu-system-i386 -cdrom $(ISO) -boot d -m 512M

# Executar com debug
debug: $(ISO)
	@echo "🐛 Executando com debug..."
	qemu-system-i386 -cdrom $(ISO) -m 512M -s -S

# Help
help:
	@echo "Comandos disponíveis:"
	@echo "  make        - Compila tudo e cria ISO"
	@echo "  make run    - Executa no QEMU"
	@echo "  make debug  - Executa com debug (GDB)"
	@echo "  make clean  - Limpa arquivos compilados"
	@echo "  make help   - Mostra esta ajuda"

.PHONY: all clean run debug help
