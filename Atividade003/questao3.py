def main():
    idade = int(input("Digite a Sua idade: "))

    if idade >= 70:
        print("Novos 50")
    elif idade >= 21:
        print("Adulto")
    elif idade < 21:
        print("Jovem")
    
if __name__ == "__main__":
    main()