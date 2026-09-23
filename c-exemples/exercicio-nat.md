Para resolver o exercício proposto, você pode seguir os passos abaixo para criar um código em C que calcule o novo valor total recebido pela pessoa e o valor pago por hora, considerando uma jornada com 6 horas diárias de segunda a sexta-feira.

1. **Calcular o novo salário após o reajuste de 5%**: Primeiro, você precisa calcular o novo salário após o reajuste de 5%. Isso pode ser feito multiplicando o salário original por 1.05 (100% + 5%).

2. **Calcular o valor total recebido**: O valor total recebido inclui o salário reajustado, o valor da refeição diária e os benefícios de plano de saúde participativo. Como o valor da refeição diária foi atualizado para R$ 28,00, você deve usar esse valor para calcular o total.

3. **Calcular o valor pago por hora**: Para calcular o valor pago por hora, você precisa dividir o valor total recebido pelo número de horas trabalhadas no mês. Como o mês tem 30 dias e 10 dias são do descanso remunerado semanal, o total de dias úteis é 20 (30 - 10). Se a jornada é de 6 horas diárias, o total de horas trabalhadas no mês é 20 \* 6 = 120 horas.

Aqui está um exemplo de código em C que realiza esses cálculos:

```c
#include <stdio.h>

int main() {
    float salarioOriginal = 3000.00; // Salário original em R$
    float reajuste = 0.05; // Reajuste de 5%
    float valorRefeicaoOriginal = 20.00; // Valor da refeição diária original em R$
    float valorRefeicaoNovo = 28.00; // Novo valor da refeição diária em R$
    float beneficios = 0.0; // Benefícios de plano de saúde participativo (assumindo 0% para simplificar)
    int diasUteis = 20; // Dias úteis no mês
    int horasDiarias = 6; // Horas trabalhadas por dia

    // Calcular o novo salário após o reajuste
    float novoSalario = salarioOriginal * (1 + reajuste);

    // Calcular o valor total recebido
    float valorTotalRecebido = novoSalario + (valorRefeicaoNovo * diasUteis) + beneficios;

    // Calcular o valor pago por hora
    float valorPorHora = valorTotalRecebido / (diasUteis * horasDiarias);

    printf("Novo valor total recebido: R$ %.2f\n", valorTotalRecebido);
    printf("Valor pago por hora: R$ %.2f\n", valorPorHora);

    return 0;
}
```

Este código assume que os benefícios de plano de saúde participativo são 0% para simplificar o cálculo. Você pode ajustar a variável `beneficios` conforme necessário.

Citations:
[1] https://codeforwin.org/c-programming/c-program-to-calculate-gross-salary-of-employee
[2] https://www.quora.com/How-do-we-write-a-C-program-to-calculate-the-gross-salary-of-a-worker-at-the-end-of-the-month
[3] https://stackoverflow.com/questions/40601621/c-programming-function-to-calculate-salary
[4] https://www.youtube.com/watch?v=PM-2fqS9XCA
[5] https://stackoverflow.com/questions/63316347/c-program-for-salary-increment-calculation-using-structure
[6] https://www.geeksforgeeks.org/program-to-calculate-gross-salary-of-a-person/
[7] https://www.chegg.com/homework-help/questions-and-answers/write-program-c-language-calculate-gross-salary-gross-salary-sum-basic-salary-allowances-p-q67745822
[8] https://www.youtube.com/watch?v=NZmu8BoSqD8
[9] https://www.indeed.com/career-advice/career-development/how-to-calculate-gross-pay
[10] https://www.youtube.com/watch?v=TSyV8nwYvC0
