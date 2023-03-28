def main():
  num1 = float(input("Digite um numero:"))
  num2 = float(input("Digite outro numero:"))

  if num1 > num2:
    print(f"O maior numero é o:{num1: .2f}")
  else:
    print(f"O maior numero é o:{num2: .2f}")  

if __name__ == "__main__":
  main()