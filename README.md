Interpretador e Depurador Brainfuck em ARM QEMU

Este projeto consiste no desenvolvimento de um interpretador e depurador para a linguagem de programação Brainfuck, 
projetado para ser executado em um ambiente de emulação ARM usando o QEMU. O objetivo principal foi aplicar e consolidar os conceitos de arquitetura de microprocessadores e sistemas microprocessados.

Integrantes

    João Felipe de Souza Melo

    Lucas Suzin Bertan

    Ian Andrade de Magalhães

Sobre o Projeto

O interpretador Brainfuck executa diretamente as instruções do código-fonte, sem a necessidade de compilação para código de máquina. 
A linguagem, conhecida por sua simplicidade, manipula uma "fita de memória" (um array de bytes) e um ponteiro.

nta o ponteiro da memória.

+
	

Incrementa o valor do byte no qual o ponteiro está.

-
	

Decrementa o valor do byte no qual o ponteiro está.

.
	

Imprime o valor do byte atual como um caractere.

,
	

Lê um caractere e armazena seu valor no byte atual.

[
	

Se o byte atual for zero, pula para o ] correspondente.

]
	

Se o byte atual não for zero, volta para o [ correspondente.
Estrutura do Código

O projeto é dividido em arquivos com funções específicas:

    startup.s: Arquivo em Assembly que define o ponto de entrada (_start) e inicializa a execução na função main em C.

    linker.ld: Define a organização da memória do programa, controlando a disposição das seções de código (.text), dados inicializados (.data) e dados não inicializados (.bss).

    main.c: Contém a lógica principal do interpretador. Ele percorre o código Brainfuck e, através de um switch, executa as ações correspondentes a cada comando, manipulando a "fita de memória" (static char memory[MAX_MEMORY_SIZE]) e o ponteiro (pos_memoria).

    Makefile: Automatiza o processo de compilação, usando o compilador arm-none-eabi-gcc para gerar o arquivo executável kernel.bin.

Modo de Depuração

O projeto inclui um modo de depuração robusto, ativado pelo comando d, que oferece as seguintes funcionalidades:

    Ver conteúdo da memória (m): Permite inspecionar um intervalo de memória específico.

    Adicionar breakpoints: Permite definir pontos de parada no código para análise.

    Execução passo a passo (n): Executa o próximo caractere do programa.

    Executar até o próximo breakpoint (c): Continua a execução até encontrar o próximo ponto de parada.

    Ver posição no código: Sinaliza a posição atual no código-fonte.

    Identificar loops: Sinaliza quando o interpretador está dentro de um loop e exibe a parte do código.

Como Compilar e Executar
Pré-requisitos

    Um ambiente com o compilador arm-none-eabi-gcc e o emulador QEMU.

    Instalação no WSL (Windows Subsystem for Linux):

    sudo apt update
    sudo apt install qemu-system-arm qemu-user-static gcc-arm-linux-gnueabihf build-essential

Compilação

Navegue até o diretório raiz do projeto e execute o Makefile:

make

Este comando irá gerar o arquivo kernel.bin, o binário executável para a arquitetura ARM.
Execução no QEMU

Carregue e execute o kernel.bin no emulador QEMU:

qemu-system-arm -M versatilepb -nographic -kernel kernel.bin

Após o início, o programa exibirá um menu de comandos, permitindo interações no modo normal (carregar e executar programas Brainfuck) ou no modo de depuração.
