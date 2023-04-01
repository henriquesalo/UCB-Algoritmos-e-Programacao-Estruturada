def main():
    idade = int(input("Digite a Sua idade: "))

    if idade <= 0:
        print("Não Nasceu")
    if idade <= 15:
        print("Não Vota")
    if idade == 16:
        print("Opcional")
    if idade == 17:
        print("Opcional")
    if idade >= 18:
        print("Obrigatório")
    if idade == 41:
        print("Ganhou um premio e nao vota")
    if idade == 65:
        print("Opcional")
    if idade == 88:
        print("Ganhou um premio e nao vota")

if __name__ == "__main__":
    main()