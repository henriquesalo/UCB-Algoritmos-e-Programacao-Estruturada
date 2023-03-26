def main():
    custo = float(input("Digite o custo da mercadoria:"))
    frete = float(input("Digite o frete da mercadoria:"))
    despesas = float(input("Digite as eventuais despesas da mercadoria:"))
    valor_venda = float(input("Digite o valor de venda da mercadoria:"))
    custo_total = custo + frete + despesas
    lucro = (valor_venda - custo_total) / valor_venda * 100.0
    print(f'A mercadoria tem {lucro: .2f}% de margem de lucro')

if __name__ == "__main__":
    main()