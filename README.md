# RosanaOS

Meu projeto de estudo para desenvolver um sistema operacional do zero utilizando C++, Assembly e arquitetura x86_64.

## Objetivo

Criar um sistema operacional funcional para aprender conceitos avançados de:

* Arquitetura de Computadores
* Sistemas Operacionais
* Programação de Baixo Nível
* Gerenciamento de Memória
* Sistemas de Arquivos
* Redes
* Desenvolvimento de Kernel

---

# Roadmap

## Fase 0 - Preparação do Ambiente

### Objetivos

* Configurar o ambiente de desenvolvimento.
* Aprender os conceitos básicos necessários.

### Estudar

* C++
* Assembly x86_64
* Git
* GCC/G++
* NASM
* QEMU
* GDB
* Processo de Boot
* BIOS e UEFI

### Entregáveis

* Ambiente funcionando.
* Projeto inicial criado no GitHub.

---

## Fase 1 - Primeiro Kernel

### Objetivos

Inicializar um kernel simples e exibir uma mensagem na tela.

### Estudar

* GRUB
* Multiboot
* Estrutura de um Kernel
* Geração de ISO bootável

### Entregáveis

Exibir:

RosanaOS v0.1

---

## Fase 2 - Saída de Vídeo

### Objetivos

Escrever diretamente na memória de vídeo.

### Estudar

* VGA Text Mode
* Memory-Mapped I/O
* Endereço 0xB8000

### Entregáveis

Implementar:

print("Olá Mundo");

---

## Fase 3 - Driver de Teclado

### Objetivos

Receber entrada do usuário.

### Estudar

* Interrupções (IRQs)
* PIC
* Scancodes PS/2

### Entregáveis

Digitar texto no terminal.

---

## Fase 4 - Terminal

### Objetivos

Criar uma interface de linha de comando.

### Comandos iniciais

* help
* clear
* version

### Estudar

* Buffers
* Parsing de comandos
* Manipulação de Strings

### Entregáveis

RosanaOS>

---

## Fase 5 - Gerenciamento de Memória

### Objetivos

Implementar alocação dinâmica.

### Estudar

* Heap
* Stack
* Paging
* Memória Virtual

### Entregáveis

Implementar:

kmalloc()
kfree()

---

## Fase 6 - Multitarefa

### Objetivos

Executar múltiplos processos.

### Estudar

* Scheduler
* Context Switching
* Processos
* Threads

### Entregáveis

Executar duas ou mais tarefas simultaneamente.

---

## Fase 7 - Sistema de Arquivos

### Objetivos

Salvar e carregar arquivos.

### Estudar

* FAT12
* FAT16
* FAT32
* Estrutura de discos

### Entregáveis

Criar, salvar e ler arquivos.

---

## Fase 8 - Driver de Disco

### Objetivos

Comunicação com dispositivos de armazenamento.

### Estudar

* ATA
* SATA
* Controladores de armazenamento

### Entregáveis

Leitura e escrita em disco.

---

## Fase 9 - Modo Gráfico

### Objetivos

Desenhar elementos na tela.

### Estudar

* Framebuffer
* VESA
* GOP (UEFI Graphics Output Protocol)

### Entregáveis

Implementar:

* drawPixel()
* drawLine()
* drawRectangle()
* drawText()

---

## Fase 10 - Interface Gráfica

### Objetivos

Criar uma área de trabalho simples.

### Componentes

* Janela
* Botão
* Menu
* Barra de tarefas

### Entregáveis

Primeira interface gráfica funcional.

---

## Fase 11 - Programas de Usuário

### Objetivos

Executar aplicações fora do kernel.

### Estudar

* User Mode
* Kernel Mode
* ELF
* System Calls

### Entregáveis

Executar programas independentes.

---

## Fase 12 - Rede

### Objetivos

Conectar o sistema à internet.

### Estudar

* Ethernet
* TCP/IP
* ARP
* DNS
* DHCP

### Entregáveis

Comunicação em rede funcional.

---

# Recursos de Estudo

## Livros

* Operating Systems: Three Easy Pieces (OSTEP)
* Operating System Concepts
* Modern Operating Systems

## Sites

* https://wiki.osdev.org
* https://littleosbook.github.io
* https://www.kernel.org

---

# Metas Futuras

* [ ] Shell avançado
* [ ] Interface gráfica completa
* [ ] Drivers USB
* [ ] Suporte a áudio
* [ ] Navegador simples
* [ ] Porta para ARM (Raspberry Pi)
* [ ] Executar em hardware real

---

"Entender um computador significa construir um."
