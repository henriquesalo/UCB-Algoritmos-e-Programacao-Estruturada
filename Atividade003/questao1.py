def main():
    nota1 = float(input("Digite a Sua Nota da Prova 1: "))
    nota2 = float(input("Digite a Sua Nota da Prova 2: "))
    media = (nota1 + nota2) / 2

    print(f"Nota Final: {media: .2f}")

if __name__ == "__main__":
    main()