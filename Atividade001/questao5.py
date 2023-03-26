def main():
    idade_anos = int(input("Digite sua idade em anos:"))
    idade_meses = int(input("Digite sua idade em meses:"))
    idade_dias = int(input("Digite sua idade em dias:"))
    idade_dias += idade_anos*365 + idade_meses*30
    print(f"Você possui {idade_dias} dias de idade.")

if __name__ == "__main__":
    main()