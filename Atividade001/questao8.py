def main():
    quant_carros = int(input("Digite o número de carros vendidos:"))
    valor_vendas = float(input("Digite o valor total de vendas:"))
    salario_fixo = float(input("Digite seu salário fixo:"))
    valor_carro = float(input("Digite o valor fixo recebido por carro:"))
    salario_final = (quant_carros * valor_carro) + salario_fixo + (valor_vendas * 5 / 100.0)
    print(f"Salário final = R$ {salario_final: .2f}")

if __name__ == "__main__":
    main()