### Dicas de implementação:

* Sempre utilizar a mesma implementação do algoritmo tanto na versão serial quando na versão paralela da aplicação.
* Para utilizar o comando #pragma parallel for é preciso que o *loop* seja implementado em sua forma **canônica** (sem alteração da assinatura vinda de dentro do loop).  

### Speedup

```
 Ts / Tp
 
/*
    Ts = Tempo Serial
    Tp = Tempo Paralelo
*/
```

### Eficiência

```
E = S / p;

/*
    E = Eficiência
    S = SpeedUp
    p = Número de threads
    
    Quanto mais próximo de 1, maior eficiência. 
    Os valores sempre estarão entre 0 e 1
*/
```

### Escalabilidade

Capacidade da aplicação de manter a eficiência confirme a quantidade de trabalho e a quantidade de *threads* aumenta.  
O programa passa a apresentar **perde de escalabilidade** a partir do momento em que o aumento de trabalotrabalho aliado ao aumento de *threads* gera perda de eficiência.

### Speedup