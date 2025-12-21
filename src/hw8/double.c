#include <stdint.h>
#include <stdio.h>

typedef union {
    double value;
    uint64_t bits;
} Number;

int main()
{
    Number num;

    printf("Введите число: ");
    if (scanf("%lf", &num.value) != 1) {
        return 1;
    }

    int sign_bit = (num.bits >> 63) & 1;
    char sign_char = sign_bit ? '-' : '+';

    int raw_exponent = (num.bits >> 52) & 0x7FF;

    uint64_t mantissa_bits = num.bits & 0xFFFFFFFFFFFFF;

    if (raw_exponent == 0) {
        if (mantissa_bits == 0) {
            printf("Результат: %c0.0*2^0\n", sign_char);
            return 0;
        } else {
            int p = 1 - 1023;
        }
    }

    if (raw_exponent == 0x7FF) {
        printf("Результат: %sInf/NaN\n", sign_char == '+' ? "+" : "-");
        return 0;
    }

    int p = raw_exponent - 1023;

    Number m_builder;

    m_builder.bits = (0ULL << 63) | (1023ULL << 52) | mantissa_bits;

    printf("Результат: %c%.17g*2^%d\n", sign_char, m_builder.value, p);

    return 0;
}