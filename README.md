# RosanaOS 🖥️

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![Fase](https://img.shields.io/badge/fase-2%20%2F%2012-blue)
![Linguagem](https://img.shields.io/badge/C%2B%2B-11-blue)
![Assembly](https://img.shields.io/badge/ASM-x86--64-red)
![Licença](https://img.shields.io/badge/license-MIT-green)

Sistema operacional desenvolvido do zero como projeto de aprendizado em Ciência da Computação.

---

## Status Atual 🚀

**Fase atual:** Fase 2 - Saída de Vídeo (em desenvolvimento)

**Últimas conquistas:** 
- ✅ Kernel bootando com sucesso
- ✅ Mensagem "RosanaOS v0.1" exibida na tela
- ✅ Ambiente de desenvolvimento configurado
- ✅ Makefile automatizado
- ✅ ISO bootável criada

**Próximos passos:**
- Implementar função `print()`
- Estudar VGA Text Mode
- Entender Memory Mapped I/O

---

## Objetivo

Este projeto tem como objetivo estudar e aplicar conceitos fundamentais de:

- Arquitetura de Computadores
- Sistemas Operacionais
- Programação de Baixo Nível
- Gerenciamento de Memória
- Estruturas de Dados
- Sistemas de Arquivos
- Concorrência
- Redes de Computadores

O objetivo **não** é criar um substituto para Windows ou Linux, mas compreender como um computador funciona internamente construindo um sistema operacional próprio.

---

## Como Compilar e Executar

### Pré-requisitos

Instale as ferramentas necessárias:

```bash
sudo apt update
sudo apt install build-essential nasm qemu-system-x86 grub-pc-bin xorriso make
```

### Compilar

```bash
make clean
make
```

### Executar

```bash
make run
```

### Comandos úteis do Makefile

| Comando | Descrição |
|---------|-----------|
| `make` | Compila tudo e cria a ISO |
| `make clean` | Limpa arquivos compilados |
| `make run` | Executa no QEMU |
| `make debug` | Executa com suporte a debug (GDB) |
| `make serial` | Executa com saída serial |
| `make help` | Mostra ajuda com todos os comandos |

---

## Ambiente de Desenvolvimento

### Ferramentas Necessárias

| Ferramenta | Descrição |
|------------|-----------|
| **Git** | Versionamento do projeto |
| **VS Code** | Editor de código principal |
| **GCC / G++** | Compilador C/C++ |
| **NASM** | Assembler para código de baixo nível |
| **QEMU** | Emulador para testar o sistema |
| **Make** | Automação da compilação |

### Ferramentas Recomendadas

| Ferramenta | Descrição |
|------------|-----------|
| **WSL2 + Ubuntu** | Ambiente Linux no Windows |
| **GDB** | Depuração do kernel |
| **Valgrind** | Verificação de vazamentos de memória |
| **Clang-format** | Formatação de código |

---

## Conhecimentos Necessários

### Fundamentos

Antes de iniciar o desenvolvimento é importante entender:

- Como um computador inicializa (boot sequence)
- O que é BIOS e UEFI
- O que é um Bootloader (GRUB)
- O que é um Kernel
- Como a CPU executa instruções
- Diferença entre hardware e software
- Modo protegido vs modo real

### Linguagens

**C++** - Linguagem principal do kernel

Tópicos importantes:
- Funções e sobrecarga
- Ponteiros e referências
- Classes e estruturas
- Manipulação de memória
- Namespaces
- Templates (básico)
- `extern "C"` para linkage com assembly

**Assembly x86-64** - Para boot e interação com hardware

Tópicos importantes:
- Registradores (EAX, EBX, ECX, EDX, ESP, EBP, EIP)
- Instruções básicas (mov, add, sub, cmp, jmp, call, ret)
- Stack (push, pop)
- Chamadas de função (calling conventions)
- Interrupções (int)
- Modo 32-bit protegido

---

## Roadmap de Desenvolvimento

### Fase 0 - Preparação ✅ (CONCLUÍDO)

**Objetivos:**
- [x] Instalar ferramentas necessárias
- [x] Configurar ambiente de desenvolvimento
- [x] Criar repositório no GitHub
- [x] Entender o processo de boot

**Estudar:**
- BIOS e UEFI
- Processo de inicialização
- Assembly básico
- Estrutura de um sistema operacional

**Resultado:**
- Ambiente pronto para desenvolvimento
- Compreensão teórica do boot

---

### Fase 1 - Primeiro Kernel ✅ (CONCLUÍDO)

**Objetivos:**
- [x] Criar um kernel mínimo capaz de iniciar
- [x] Configurar GRUB e Multiboot
- [x] Exibir "RosanaOS v0.1" na tela

**Estudar:**
- GRUB (Grand Unified Bootloader)
- Especificação Multiboot
- Estrutura de kernel ELF
- Linkers e linker scripts
- VGA Text Mode básico

**Resultado:**
- Kernel bootando com sucesso
- Mensagem exibida na tela
- ISO bootável criada

**Arquivos criados:**
- `kernel/multiboot.asm` - Cabeçalho Multiboot
- `kernel/boot.asm` - Ponto de entrada
- `kernel/kernel.cpp` - Kernel em C++
- `linker.ld` - Script do linker
- `Makefile` - Automação de compilação

---

### Fase 2 - Saída de Vídeo (EM ANDAMENTO)

**Objetivos:**
- [ ] Escrever texto diretamente na tela
- [ ] Implementar função `print()`
- [ ] Controlar cores e posicionamento

**Estudar:**
- VGA Text Mode (modo texto)
- Memory Mapped I/O (mapeamento de memória)
- Buffer de vídeo (0xB8000)
- Atributos de cor (0x07 = branco/preto)

**Resultado esperado:**
```cpp
print("Hello, World!");  // Escreve na tela
print("RosanaOS", 0x0A); // Escreve em verde
```

---

### Fase 3 - Entrada pelo Teclado

**Objetivos:**
- [ ] Capturar entrada do usuário
- [ ] Processar scancodes do teclado

**Estudar:**
- Interrupções (IRQs)
- PIC (Programmable Interrupt Controller)
- Teclado PS/2
- Scancodes (conjunto 1, 2, 3)
- Fila de eventos

**Resultado esperado:**
- Sistema responde a teclas pressionadas
- Buffer de teclado funcionando

---

### Fase 4 - Terminal

**Objetivos:**
- [ ] Criar uma interface de linha de comando
- [ ] Implementar comandos básicos

**Comandos mínimos:**
- `help` - Lista comandos disponíveis
- `clear` - Limpa a tela
- `version` - Mostra versão do sistema
- `echo` - Repete o texto digitado
- `reboot` - Reinicia o sistema

**Resultado esperado:**
```
RosanaOS> help
Comandos disponíveis: help, clear, version, echo, reboot
RosanaOS> version
RosanaOS v0.1
```

---

### Fase 5 - Gerenciamento de Memória

**Objetivos:**
- [ ] Implementar alocação dinâmica de memória
- [ ] Criar heap e stack

**Estudar:**
- Heap e Stack
- Paginação de memória
- Memória virtual vs física
- Alocadores (first-fit, best-fit, buddy system)
- Gerenciamento de blocos

**Resultado esperado:**
```cpp
void* ptr = kmalloc(1024);  // Aloca 1KB
kfree(ptr);                  // Libera memória
```

---

### Fase 6 - Multitarefa

**Objetivos:**
- [ ] Executar múltiplas tarefas simultaneamente
- [ ] Implementar escalonador (scheduler)

**Estudar:**
- Processos e threads
- Context switching (troca de contexto)
- Scheduler (round-robin, priority)
- Estados dos processos (ready, running, blocked, terminated)
- PCB (Process Control Block)

**Resultado esperado:**
- Múltiplas tarefas executando em paralelo
- Alternância entre processos

---

### Fase 7 - Sistema de Arquivos

**Objetivos:**
- [ ] Criar, ler e salvar arquivos
- [ ] Implementar sistema de arquivos FAT

**Estudar:**
- FAT12, FAT16, FAT32
- Estrutura de discos (setores, trilhas, cilindros)
- Boot Record (BPB)
- Tabela de alocação de arquivos (FAT)
- Diretórios (entradas de diretório)

**Resultado esperado:**
- Sistema reconhece arquivos
- Leitura e escrita de arquivos

---

### Fase 8 - Drivers de Armazenamento

**Objetivos:**
- [ ] Comunicação com dispositivos de armazenamento
- [ ] Leitura e escrita em disco

**Estudar:**
- ATA (Advanced Technology Attachment)
- SATA (Serial ATA)
- PIO (Programmed I/O)
- DMA (Direct Memory Access)
- LBA (Logical Block Addressing)

**Resultado esperado:**
- Kernel lê e escreve no disco
- Suporte a múltiplos dispositivos

---

### Fase 9 - Modo Gráfico

**Objetivos:**
- [ ] Desenhar elementos gráficos na tela
- [ ] Sair do modo texto para modo gráfico

**Estudar:**
- Framebuffer
- VESA (Video Electronics Standards Association)
- GOP (Graphics Output Protocol) para UEFI
- Pixel e resolução

**Resultado esperado:**
```cpp
drawPixel(100, 100, 0x00FF00);    // Desenha pixel verde
drawLine(0, 0, 100, 100, 0xFF0000); // Linha vermelha
drawRectangle(50, 50, 200, 150, 0x0000FF); // Retângulo azul
```

---

### Fase 10 - Interface Gráfica

**Objetivos:**
- [ ] Criar ambiente gráfico completo
- [ ] Implementar elementos de interface

**Componentes:**
- Janelas (draggable, resizable)
- Botões com ação
- Menus dropdown
- Barra de tarefas
- Cursor do mouse
- Gerenciador de janelas

**Resultado esperado:**
- Primeira área de trabalho funcional
- Interface gráfica interativa

---

### Fase 11 - Programas de Usuário

**Objetivos:**
- [ ] Executar aplicações separadas do kernel
- [ ] Implementar chamadas de sistema (system calls)

**Estudar:**
- User Mode vs Kernel Mode
- ELF (Executable and Linkable Format)
- System Calls
- Proteção de memória
- GDT (Global Descriptor Table)

**Resultado esperado:**
- Sistema executa programas externos
- Programas rodam em modo usuário
- Chamadas de sistema funcionando

---

### Fase 12 - Rede

**Objetivos:**
- [ ] Conectar o sistema à rede
- [ ] Implementar pilha TCP/IP

**Estudar:**
- Ethernet (quadros, MAC addresses)
- TCP/IP (protocolos)
- ARP (Address Resolution Protocol)
- DNS (Domain Name System)
- DHCP (Dynamic Host Configuration Protocol)
- Sockets

**Resultado esperado:**
- Comunicação de rede funcional
- Ping para outros hosts
- Conexão TCP básica

---

## Estrutura do Projeto

```
RosanaOS/
│
├── boot/                  # Arquivos de boot
│   ├── boot.asm          # Ponto de entrada (em breve)
│   └── multiboot.asm     # Cabeçalho Multiboot (em breve)
│
├── kernel/               # Núcleo do sistema
│   ├── boot.asm          # Ponto de entrada do kernel
│   ├── multiboot.asm     # Cabeçalho Multiboot
│   └── kernel.cpp        # Kernel principal em C++
│
├── drivers/              # Drivers de dispositivos
│   ├── vga/              # Driver VGA
│   ├── keyboard/         # Driver de teclado
│   ├── ata/              # Driver ATA
│   └── usb/              # Driver USB
│
├── memory/               # Gerenciamento de memória
│   ├── heap.cpp          # Alocação dinâmica
│   ├── paging.cpp        # Paginação
│   └── mmu.cpp           # Unidade de gerenciamento
│
├── filesystem/           # Sistema de arquivos
│   ├── fat.cpp           # Implementação FAT
│   └── vfs.cpp           # Virtual File System
│
├── userland/             # Programas de usuário
│   ├── shell/            # Shell
│   ├── apps/             # Aplicações
│   └── lib/              # Bibliotecas
│
├── docs/                 # Documentação
│   ├── architecture.md   # Arquitetura do sistema
│   ├── api.md           # API do kernel
│   └── development.md   # Guia de desenvolvimento
│
├── build/                # Arquivos compilados
│   ├── *.o              # Objetos
│   ├── kernel.elf       # Kernel executável
│   └── RosanaOS.iso     # ISO bootável
│
├── iso/                  # Arquivos para criação da ISO
│   └── boot/
│       └── grub/
│           └── grub.cfg  # Configuração do GRUB
│
├── tests/                # Testes
│   ├── unit/            # Testes unitários
│   ├── integration/     # Testes de integração
│   └── stress/          # Testes de estresse
│
├── tools/                # Ferramentas auxiliares
│   ├── build.sh         # Script de build
│   ├── debug.sh         # Script de debug
│   └── run.sh           # Script de execução
│
├── linker.ld             # Script do linker
├── Makefile              # Automação de compilação
├── LICENSE               # Licença do projeto
└── README.md             # Este arquivo
```

---

## Recursos de Estudo

### Documentação Online
- [OSDev Wiki](https://wiki.osdev.org/) - Principal fonte de conhecimento
- [The Little Book About OS Development](https://littleosbook.github.io/) - Guia introdutório
- [OSDev Series on YouTube](https://www.youtube.com/c/WriteyourOwnOperatingSystem) - Vídeos tutoriais

### Livros
- [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/) - Gratuito online
- [Operating System Concepts](https://www.os-book.com/) - Livro clássico
- [Modern Operating Systems](https://www.pearson.com/us/higher-education/product/Tanenbaum-Modern-Operating-Systems-4th-Edition/9780133591620.html) - Andrew Tanenbaum
- [The Design of the UNIX Operating System](https://www.amazon.com/Design-UNIX-Operating-System/dp/0132017997) - Maurice Bach

### Artigos e Tutoriais
- [Writing a Simple Operating System from Scratch](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf) - PDF guia
- [Roll Your Own Toy UNIX Clone OS](https://www.jamesmolloy.co.uk/tutorial_html/) - Tutorial passo a passo
- [OSDev Forums](https://forum.osdev.org/) - Comunidade para dúvidas

### Ferramentas
- [QEMU Documentation](https://www.qemu.org/docs/master/) - Emulador
- [GDB Documentation](https://sourceware.org/gdb/current/onlinedocs/gdb/) - Debugger
- [NASM Manual](https://www.nasm.us/doc/) - Assembler
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/) - Compilador

---

## Metas Futuras

### Curto Prazo (3 meses)
- [ ] Função `print()` completa com cores
- [ ] Buffer de tela com scroll
- [ ] Detecção de teclas
- [ ] Shell básico com `help`, `clear`, `version`
- [ ] Alocador de memória simples

### Médio Prazo (6 meses)
- [ ] Sistema de arquivos FAT12
- [ ] Multitarefa básica (round-robin)
- [ ] Gerenciamento de memória com paginação
- [ ] Interface gráfica simples
- [ ] Execução de programas em modo usuário

### Longo Prazo (1 ano)
- [ ] Interface gráfica completa com janelas
- [ ] Drivers USB e áudio
- [ ] Pilha de rede TCP/IP
- [ ] Porta para ARM (Raspberry Pi)
- [ ] Execução em hardware real
- [ ] Compilador próprio (projeto separado)

### Sonhos (2+ anos)
- [ ] Browser web básico
- [ ] Editor de texto
- [ ] Jogos simples
- [ ] Suporte a múltiplos usuários
- [ ] Distribuição para entusiastas
- [ ] Documentação completa em português

---

## Contribuição

Este é um projeto pessoal de aprendizado, mas sugestões e dicas são sempre bem-vindas!

### Como contribuir
1. Faça um fork do projeto
2. Crie uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

### Relatando problemas
- Use a seção de Issues do GitHub
- Descreva o problema em detalhes
- Inclua logs e screenshots se possível

---

## Licença

Este projeto está sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

```
MIT License

Copyright (c) 2024 Rosana

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

---

## Contato

- **Nome:** Rosana
- **Projeto:** RosanaOS
- **GitHub:** [github.com/rosana/RosanaOS](https://github.com/rosana/RosanaOS)

---

## Agradecimentos

- Comunidade OSDev pela documentação extensa
- Projetos open-source que servem de referência
- Professores e colegas que incentivam o aprendizado

---

**Desenvolvido com ❤️ e muita curiosidade por Rosana**

---

*"O melhor jeito de aprender algo é tentando ensinar ou construir do zero."*

*Última atualização: 23 de Junho de 2026*
