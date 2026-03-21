/*
Este programa demonstra como um número inteiro é armazenado na memória
do computador, byte a byte, e verifica a ordem de armazenamento conhecida
como endianness.

Informações importantes:

1. Memória é endereçada a bytes:
   - Cada endereço na memória corresponde a **um byte** (8 bits).
   - Um inteiro geralmente ocupa 4 bytes.

2. Representação hexadecimal:
   - O número 66051 em hexadecimal é 0x00010203.
   - Cada **dois dígitos hexadecimais** representam exatamente 1 byte.
     Por exemplo:
       0x00 → primeiro byte
       0x01 → segundo byte
       0x02 → terceiro byte
       0x03 → quarto byte

3. Endianness:
   - Little Endian: o byte menos significativo (menor valor) vem primeiro.
   - Big Endian: o byte mais significativo (maior valor) vem primeiro.
*/

#include <stdio.h>

int main() {
    // Declaramos um inteiro i com valor 66051.
    int i = 66051; // hexadecimal: 0x00010203

    /*
    Para acessar cada byte individualmente, usamos um ponteiro para unsigned char.
    - Um "char" ocupa exatamente 1 byte.
    - Usar "unsigned char" garante que os valores dos bytes fiquem entre 0 e 255,
      evitando números negativos (char pode ser signed dependendo do compilador).
    - Se usássemos "int*", não conseguiríamos acessar byte a byte,
      pois p + 1 avançaria 4 bytes (tamanho do int) em vez de 1 byte.
    */
    unsigned char* p = (unsigned char*) &i;

    printf("Valor do inteiro: %d (0x%08X)\n\n", i, i);
    printf("Byte | Endereço       | Decimal | Hex\n");
    printf("-----+----------------+---------+------\n");
    printf(" 0   | %p |   %3d   | 0x%02X\n"  , p+0, *(p+0), *(p+0));
    printf(" 1   | %p |   %3d   | 0x%02X\n"  , p+1, *(p+1), *(p+1));
    printf(" 2   | %p |   %3d   | 0x%02X\n"  , p+2, *(p+2), *(p+2));
    printf(" 3   | %p |   %3d   | 0x%02X\n\n", p+3, *(p+3), *(p+3));

    /*
    Verificamos se a CPU é little endian ou big endian:
    - Se o primeiro byte (*p) contiver o valor 3 (0x03), 
      significa que o byte menos significativo vem primeiro → little endian.
    - Caso contrário, é big endian.
    */
    if (*p == 3) {
        printf("CPU é little endian!\n");
    } else {
        printf("CPU é big endian!\n");
    }

    return 0;
}

/*
MEMORY (como o inteiro 0x00010203 pode estar armazenado na memória)

Endereços | Little Endian (byte menos significativo primeiro) | Big Endian (byte mais significativo primeiro)
----------+---------------------------------------------------+-------------------------------------------
x         | 0x03                                              | 0x00
x + 1     | 0x02                                              | 0x01
x + 2     | 0x01                                              | 0x02
x + 3     | 0x00                                              | 0x03

Explicação:
- Cada endereço corresponde a **um byte** de memória.
- Cada valor é representado em **hexadecimal**, dois dígitos por byte.
- Little Endian armazena o byte menos significativo (0x03) no endereço mais baixo.
- Big Endian armazena o byte mais significativo (0x00) no endereço mais baixo.
*/