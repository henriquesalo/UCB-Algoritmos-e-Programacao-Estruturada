def main():
    salario = float(input("Digite seu salário mensal atual:"))
    percentual = int(input("Digite o percentual de reajuste:"))
    novo_salario = salario + (salario * percentual / 100.0)
    print(f"{novo_salario}")

if __name__ == "__main__":
    main()