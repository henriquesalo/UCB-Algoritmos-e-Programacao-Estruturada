def configurar_referencia(nome_completo):
    # Separando o nome completo em uma lista de nomes
    nomes = nome_completo.split()
    
    # Pegando o último nome da lista
    ultimo_nome = nomes[-1].upper()
    
    # Inicializando a variável com as iniciais dos outros nomes
    iniciais = ""
    for nome in nomes[:-1]:
        iniciais += nome[0].upper() + ". "
    
    # Retornando a referência configurada
    return ultimo_nome + " " + iniciais[:-1]

nome_completo = "Joaquim Pedro Alves"
referencia = configurar_referencia(nome_completo)
print(referencia)