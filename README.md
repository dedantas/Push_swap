# 🔢 Push_swap — 42 School

Algoritmo de ordenação usando duas stacks (`a` e `b`) e um conjunto limitado de operações (`push`, `swap`, `rotate`, `reverse rotate`), com foco em minimizar o número de operações. Inclui um `checker` bonus que valida a sequência de operações.

## 🧠 Conceitos aplicados
- Estruturas de dados (listas ligadas usadas como stacks)
- Complexidade algorítmica e otimização (Big O)
- Radix sort adaptado para stacks
- Estratégias diferentes para listas pequenas vs. grandes

## ⚙️ Compilação
```bash
make            # compila push_swap
make bonus      # compila o checker
make clean      # remove .o
make fclean     # remove .o e binários
make re         # recompila do zero
```

## ▶️ Uso
```bash
./push_swap "2 1 3 6 5 8"
# imprime a sequência de operações necessárias para ordenar a stack
```

### Bonus — checker
```bash
./checker "2 1 3 6 5 8"
# em seguida, digite as operações (uma por linha) e finalize com Ctrl+D
# imprime OK se a stack ficou ordenada, KO caso contrário
```

### Testando performance
```bash
./push_swap $(shuf -i 1-500 -n 500 | tr '\n' ' ') | wc -l
```

## 🏗️ Estrutura
```
src/
├── main.c         # ponto de entrada
├── parsing.c       # validação e parsing dos argumentos
├── push.c          # operações pa/pb
├── swap.c          # operações sa/sb/ss
├── rotate.c         # operações ra/rb/rr
├── reverse.c        # operações rra/rrb/rrr
├── sort_small.c     # ordenação para listas pequenas (≤3 elementos)
├── sort_large.c      # ordenação para listas grandes
├── sort_utils.c      # funções auxiliares de ordenação
├── radix_sort.c      # implementação do radix sort adaptado
├── index.c          # indexação/normalização dos valores
├── errors.c          # tratamento de erros
└── checker.c        # bonus: validação de sequência de operações
```

## 📌 Aprendizados
Este foi o projeto que mais exigiu raciocínio algorítmico puro: pensar em como minimizar operações, escolher entre diferentes estratégias de ordenação conforme o tamanho da entrada, e validar corretude com o checker.
