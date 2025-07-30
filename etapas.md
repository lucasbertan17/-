### Etapas
1. Rodar código brainf**k no QEMU dando input estático.
2. Rodar no QEMU com input dinâmico (comando w para write e e para execute)
3. Depurador (ativar e desativar depuração com comando d)
    3.1. Ver conteudo da memoria (m 0 12)
    3.2. Ver código atual
         v   b
        ++++++++++++++++++++++++++++++++++.
    3.3. Adicionar breakpoints
    3.4. Flag que está em loop e mostrar código do loop atual 
        loop=yes [>+++<--]
    3.5. Execução até próximo breakpoint (c)
    3.6. Executar o próximo caractere (n)