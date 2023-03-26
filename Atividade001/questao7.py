def main():
    custo_fabrica = float(input("Digite o custo de fábrica:"))
    custo_final = custo_fabrica + (custo_fabrica * 28 / 100.0) + (custo_fabrica * 45 / 100.0)
    print(f"O custo final do carro é: R${custo_final: .2f}")

if __name__ == "__main__":
    main()