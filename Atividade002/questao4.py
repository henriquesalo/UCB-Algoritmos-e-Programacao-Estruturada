def main():
  salario = float(input("Digite Seu Salario: "))
  valor = float(input("Digite o valor da prestação do emprestimo: "))

  if valor > ((salario *20)/100):
    print(f"Emprestimo Não concedido")
  else:
    print("Emprestimo Concedido")


if __name__ == "__main__":
  main()