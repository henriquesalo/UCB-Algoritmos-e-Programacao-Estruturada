import math

def main():
  num = float(input("Digite um numero: "))
  num2 = num
  raiz = math.sqrt(num)
  quadrado = num2 * num2

  if num > 0:
    print(f"O quadrado do número digitado é: {quadrado}")
    print(f"A raiz desse número é: {raiz}")


if __name__ == "__main__":
  main()