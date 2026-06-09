# RosanaOS

Sistema operacional desenvolvido do zero como projeto de aprendizado em Ciência da Computação.

## Objetivo

Este projeto tem como objetivo estudar e aplicar conceitos fundamentais de:

* Arquitetura de Computadores
* Sistemas Operacionais
* Programação de Baixo Nível
* Gerenciamento de Memória
* Estruturas de Dados
* Sistemas de Arquivos
* Concorrência
* Redes de Computadores

O objetivo não é criar um substituto para Windows ou Linux, mas compreender como um computador funciona internamente construindo um sistema operacional próprio.

---

# Ambiente de Desenvolvimento

## Ferramentas Necessárias

### Git

Utilizado para versionamento do projeto.

### VS Code

Editor de código principal.

### GCC / G++

Compilador C/C++.

### NASM

Assembler utilizado para código de baixo nível e boot.

### QEMU

Emulador utilizado para executar e testar o sistema operacional.

---

## Ferramentas Recomendadas

### WSL2 + Ubuntu

Embora não seja obrigatório, facilita bastante o desenvolvimento, pois a maioria dos tutoriais e ferramentas de desenvolvimento de sistemas operacionais são voltados para Linux.

### GDB

Depuração do kernel.

### Make

Automação da compilação do projeto.

---

# Conhecimentos Necessários

## Fundamentos

Antes de iniciar o desenvolvimento é importante entender:

* Como um computador inicializa
* O que é BIOS
* O que é UEFI
* O que é um Bootloader
* O que é um Kernel
* Como a CPU executa instruções
* Diferença entre hardware e software

---

## Linguagens

### C++

Será a principal linguagem utilizada no kernel.

Tópicos importantes:

* Funções
* Ponteiros
* Referências
* Classes
* Estruturas
* Manipulação de memória
* Namespaces

### Assembly x86-64

Necessário para compreender o processo de boot e interagir diretamente com o hardware.

Tópicos importantes:

* Registradores
* Instruções básicas
* Stack
* Chamadas de função
* Interrupções

---

# Roadmap de Desenvolvimento

## Fase 0 - Preparação

### Objetivos

* Instalar ferramentas
* Configurar ambiente
* Criar repositório
* Entender o processo de boot

### Estudar

* BIOS
* UEFI
* Processo de inicialização
* Assembly básico
* Estrutura de um sistema operacional

### Conclusão

Compreender o que acontece desde o momento em que o computador é ligado até a execução do sistema operacional.

---

## Fase 1 - Primeiro Kernel

### Objetivos

Criar um kernel mínimo capaz de iniciar.

### Estudar

* GRUB
* Multiboot
* Estrutura de kernel
* Linkers

### Resultado esperado

Exibir:

RosanaOS v0.1

---

## Fase 2 - Saída de Vídeo

### Objetivos

Escrever texto diretamente na tela.

### Estudar

* VGA Text Mode
* Memory Mapped I/O

### Resultado esperado

Implementar função:

print()

---

## Fase 3 - Entrada pelo Teclado

### Objetivos

Capturar entrada do usuário.

### Estudar

* Interrupções
* IRQs
* PIC
* Teclado PS/2
* Scancodes

### Resultado esperado

Receber texto digitado.

---

## Fase 4 - Terminal

### Objetivos

Criar uma interface de linha de comando.

### Comandos mínimos

* help
* clear
* version

### Resultado esperado

RosanaOS>

---

## Fase 5 - Gerenciamento de Memória

### Objetivos

Implementar alocação dinâmica.

### Estudar

* Heap
* Stack
* Paginação
* Memória virtual

### Resultado esperado

Implementar:

* kmalloc()
* kfree()

---

## Fase 6 - Multitarefa

### Objetivos

Executar múltiplas tarefas.

### Estudar

* Processos
* Threads
* Scheduler
* Context Switching

### Resultado esperado

Múltiplas tarefas executando simultaneamente.

---

## Fase 7 - Sistema de Arquivos

### Objetivos

Persistência de dados.

### Estudar

* FAT12
* FAT16
* FAT32
* Estrutura de discos

### Resultado esperado

Criar, ler e salvar arquivos.

---

## Fase 8 - Drivers de Armazenamento

### Objetivos

Comunicação com dispositivos de armazenamento.

### Estudar

* ATA
* SATA

### Resultado esperado

Leitura e escrita em disco.

---

## Fase 9 - Modo Gráfico

### Objetivos

Desenhar elementos na tela.

### Estudar

* Framebuffer
* VESA
* GOP

### Resultado esperado

Implementar:

* drawPixel()
* drawLine()
* drawRectangle()
* drawText()

---

## Fase 10 - Interface Gráfica

### Objetivos

Criar ambiente gráfico.

### Componentes

* Janelas
* Botões
* Menus
* Barra de tarefas

### Resultado esperado

Primeira área de trabalho funcional.

---

## Fase 11 - Programas de Usuário

### Objetivos

Executar aplicações separadas do kernel.

### Estudar

* User Mode
* Kernel Mode
* ELF
* System Calls

### Resultado esperado

Executar programas externos.

---

## Fase 12 - Rede

### Objetivos

Conectar o sistema à rede.

### Estudar

* Ethernet
* TCP/IP
* ARP
* DNS
* DHCP

### Resultado esperado

Comunicação de rede funcional.

---

# Estrutura do Projeto

```text
RosanaOS/
│
├── boot/
├── kernel/
├── drivers/
├── memory/
├── filesystem/
├── userland/
├── docs/
├── build/
├── iso/
├── tests/
└── README.md
```

---

# Recursos de Estudo

* OSDev Wiki
* The Little Book About OS Development
* Operating Systems: Three Easy Pieces
* Operating System Concepts
* Modern Operating Systems

---

# Metas Futuras

* [ ] Shell avançado
* [ ] Interface gráfica completa
* [ ] Drivers USB
* [ ] Suporte a áudio
* [ ] Rede completa
* [ ] Porta para ARM (Raspberry Pi)
* [ ] Execução em hardware real
